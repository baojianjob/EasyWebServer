// SOCKET ����
// wbj 2003.4.4
// SOCKET ����
// wbj 2003.4.4
// wbj 2003.6.24  add SendTo, ReceiveFrom
// wbj 2003.10    add SendAll, RecvAll
// wbj 2003.10.27 
//     add SetSendBufSize, SetRecvBufSize, GetSendBufSize, GetRecvBufSize
// wbj 2004.11.23 Modify RecvAllStr

//#include <winsock2.h>
#include "stdafx.h"
#include "socket.h"

#pragma comment(lib, "Ws2_32.lib")

namespace minilib
{

bool BaseSOCKET::SocketInit(int MajorVersion, int MinorVersion)  // static
{
  WORD Version = MAKEWORD(MajorVersion, MinorVersion);;
  WSADATA WSData;

  if(WSAStartup(Version, &WSData) != 0)
    return false;
  if(LOBYTE(WSData.wVersion ) != MajorVersion || HIBYTE(WSData.wVersion) != MinorVersion)
  {
    WSACleanup();
    return false; 
  }
  return true;
}

bool BaseSOCKET::IsReadable()
{
  assert(hSocket != INVALID_SOCKET);

  timeval TimeOut = { 0, 0 };
  
  fd_set ReadSet;
  FD_ZERO(&ReadSet);
  FD_SET(hSocket,&ReadSet);
  int Status = select(0, &ReadSet, 0, 0, &TimeOut);

  if(Status == 0 || Status == SOCKET_ERROR)
    return false;
  
  return true;
}

bool BaseSOCKET::IsWriteable()
{
  return WaitData(false, 0);
}

int BaseSOCKET::SendTo(const void *pBuf, int BufLen, UINT HostPort, const char *pHostAddress, int Flags)
{
  SOCKADDR_IN sockAddr;

  memset(&sockAddr, 0, sizeof(sockAddr));

  //LPSTR lpszAscii = T2A((LPTSTR)pHostAddress);
  sockAddr.sin_family = AF_INET;

  if (pHostAddress == NULL)
    sockAddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
  else
  {
    sockAddr.sin_addr.s_addr = inet_addr(pHostAddress);
    if (sockAddr.sin_addr.s_addr == INADDR_NONE)
    {
      LPHOSTENT lphost;
      lphost = gethostbyname(pHostAddress);
      if(lphost != NULL)
        sockAddr.sin_addr.s_addr = ((LPIN_ADDR)lphost->h_addr)->s_addr;
      else
      {
        WSASetLastError(WSAEINVAL);
        return SOCKET_ERROR;
      }
    }
  }

  sockAddr.sin_port = htons((u_short)HostPort);

  return sendto(hSocket, (const char *)pBuf, BufLen, Flags, (SOCKADDR*)&sockAddr, sizeof(sockAddr));
}

int BaseSOCKET::ReceiveFrom(void *pBuf, int BufLen, char *pSocketAddress, int AddrBufSize, UINT &rSocketPort, int Flags)
{
  SOCKADDR_IN sockAddr;
  memset(&sockAddr, 0, sizeof(sockAddr));

  int nSockAddrLen = sizeof(sockAddr);
  int nResult = recvfrom(hSocket, (char *)pBuf, BufLen, Flags, (SOCKADDR*)&sockAddr, &nSockAddrLen);
  if(nResult != SOCKET_ERROR)
  {
    rSocketPort = ntohs(sockAddr.sin_port);
    lstrcpyn(pSocketAddress, inet_ntoa(sockAddr.sin_addr), AddrBufSize);
  }
  return nResult;
}

int BaseSOCKET::SendAll(const BYTE *pBuf, int Size, int TimeOutSecond /* = -1*/)
{
#if 0 && defined _DEBUG
  FILE *pFile = fopen("d:\\http.txt", "ab");
  if(pFile != NULL)
  {
    fwrite(pBuf, 1, Size, pFile);
    fclose(pFile);
  }
#endif

  if(TimeOutSecond > 0)
    SetSendTimeout(TimeOutSecond * 1000);

  int Left = Size;
  while(Left > 0)
  {
    //Sleep(500);
    int Ret = send(hSocket, (const char *)pBuf, Left, 0);
    if(Ret <= 0)
    {
      if(Ret == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK)
      {
        int MilliSeconds = GetSendTimeout();
        if(MilliSeconds <= 0)
          MilliSeconds = 60 * 1000;

        if(!WaitData(false, MilliSeconds))
          break;//return false;
        continue;
      }
      else
      {
        //int Err = WSAGetLastError();
        break;//return false; // ��������
      }
    }
    Left -= Ret;
    pBuf += Ret;
  }
  return Size - Left;
}

bool BaseSOCKET::WaitData(bool bIsForRead, DWORD MilliSeconds)
{
  assert(hSocket != INVALID_SOCKET);

  timeval TimeOut;
  TimeOut.tv_sec = MilliSeconds / 1000;
  TimeOut.tv_usec = MilliSeconds % 1000 * 1000;

  fd_set SocketSet;
  FD_ZERO(&SocketSet);
  FD_SET(hSocket, &SocketSet);

  if(bIsForRead)
    return select(0, &SocketSet, 0, 0, &TimeOut) > 0;
  else
    return select(0, 0, &SocketSet, 0, &TimeOut) > 0;
}

int BaseSOCKET::RecvAll(BYTE *pBuf, int Size, int TimeOutSecond/* = -1*/)
{ // �������������ͷ�������socket������
  if(TimeOutSecond > 0)
    SetRecvTimeout(TimeOutSecond * 1000);

  int Left = Size;
  while(Left > 0)
  {
    int Ret = recv(hSocket, (char *)pBuf, Left, 0);
    if(Ret <= 0)
    {
      if(Ret == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK)
      {
        int MilliSeconds = GetRecvTimeout();
        if(MilliSeconds <= 0)
          MilliSeconds = 60 * 1000;
          
        if(!WaitData(true, MilliSeconds))
          break;//return false;
        continue;
      }
      else
        break;//return false; // ��������
    }

    Left -= Ret;
    pBuf += Ret;
  }
  return Size - Left;
}

bool BaseSOCKET::RecvAllStr(char *pBuf, int Size, const char *pEndFlag)
{ // �������������ͷ�������socket������
  int Total = 0;
  int EndFlagLen = lstrlen(pEndFlag);
  Size--;
  while(Size - Total > 0)
  {
    int Ret = recv(hSocket, pBuf + Total, Size - Total, 0);
    
    if(Ret <= 0)
    {
      if(Ret == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK)
      {
        int MilliSeconds = GetRecvTimeout();
        if(MilliSeconds <= 0)
          MilliSeconds = 60 * 1000;
          
        if(!WaitData(true, MilliSeconds))
          return false;  // ������ģʽ�ĳ�ʱ
        continue;
      }
      else
        return false; // ��������
    }

    Total += Ret;
    pBuf[Total] = '\0';
    if(strcmp(pBuf + Total - EndFlagLen, pEndFlag) == 0)
      return true;
  }
  return false;  // �ռ���
}

bool BaseSOCKET::RecvAllStr2(char *pBuf, int Size, const char *pEndFlag)
{ // �������������ͷ�������socket������
  int Total = 0;
  int EndFlagLen = lstrlen(pEndFlag);
  Size--;
  while(Size - Total > 0)
  {
    int Ret = recv(hSocket, pBuf + Total, Size - Total, 0);
    
    if(Ret == 0)
    {
      // �ͻ��������Ͽ�
      return false; 
    }
    else if(Ret < 0)
    {
      if(Ret == SOCKET_ERROR)
      {
        int Err = WSAGetLastError();
        if(Err == WSAEWOULDBLOCK)
        {
          int MilliSeconds = GetRecvTimeout();
          if(MilliSeconds <= 0)
            MilliSeconds = 60 * 1000;

          if(!WaitData(true, MilliSeconds))
          {
            // ������ģʽ�ĳ�ʱ
            return false;
          }
          continue;
        }
        else if(Err == WSAETIMEDOUT)
        {
          // ����ģʽ�ĳ�ʱ
          return false;
        }
        else
        {
          // ��������
          return false;
        }
      }
      else
      {
        assert(false);
        return false; 
      }
    }

    Total += Ret;
    pBuf[Total] = '\0';
    if(strcmp(pBuf + Total - EndFlagLen, pEndFlag) == 0)
      return true;
  }
  return false;  // �ռ���
}

/*
// ����ʵ���յ��������ֽ���
int BaseSOCKET::ReceiveEx(BYTE *pRecvBuffer, int BufSize, UINT TimeOutSecond)
{
  int CurGetSize = 0;
  DWORD BeginTime = ::GetTickCount();
  while(1)
  {
    if(::GetTickCount() - BeginTime > TimeOutSecond * 1000L)  // �ж��Ƿ�ʱ
      break;

    bool bIsReadable = IsReadable();  // �ж��Ƿ�ɶ�
    if(!bIsReadable)
    {
      Sleep(100);
      continue;
    }
    else
    {
      int TempSize = recv(hSocket, (char *)(pRecvBuffer + CurGetSize), BufSize - CurGetSize, 0);
      if(TempSize > 0)
      {
        CurGetSize += TempSize;
        if(CurGetSize >= BufSize)
          break;
        BeginTime = ::GetTickCount();    // ������ʼʱ��
      }
    }
  }

  return CurGetSize;
}

// ע���� free �����ͷŷ��ص��ڴ�
char *BaseSOCKET::ReceiveEx(const char *pEndFlagStr, UINT TimeOutSecond, UINT *pRecvSize)
{
  int BufSize    = 1000;  // ��ʼ�����ڴ��С
  int CurGetSize = 0;     // ���յ����ֽ���
  
  char *pRecvBuffer = (char *)malloc(BufSize);
  assert(pRecvBuffer != NULL);
  memset(pRecvBuffer, 0, BufSize);

  DWORD BeginTime = ::GetTickCount();
  while(1)
  {
    if(::GetTickCount() - BeginTime > TimeOutSecond * 1000L)  // �ж��Ƿ�ʱ
    {
      free(pRecvBuffer);
      return NULL;
    }

    bool bIsReadable = IsReadable();  // �ж��Ƿ�ɶ�
    if(!bIsReadable)
    {
      Sleep(100);
      continue;
    }
    else
    {
      if(BufSize - CurGetSize - 1 <= 0)  // ��ǰ������ڴ治��
      {
        BufSize += 2000;
        pRecvBuffer = (char *)realloc(pRecvBuffer, BufSize);  // �����ڴ����
        assert(pRecvBuffer);
        memset(pRecvBuffer + CurGetSize, 0, BufSize - CurGetSize);
      }
      
      int TempSize = recv(hSocket, pRecvBuffer + CurGetSize, BufSize - CurGetSize - 1, 0);
      if(TempSize > 0)
      {
        CurGetSize += TempSize;
        if(strstr(pRecvBuffer, pEndFlagStr) != NULL)  // ���ҽ��յĽ�����־
          break;
        BeginTime = ::GetTickCount();    // ������ʼʱ��
      }
    }
  }

  if(pRecvSize != NULL)
    *pRecvSize = CurGetSize;

  return pRecvBuffer;
}
*/
bool BaseSOCKET::Connect(DWORD Ip, int Port)
{
  assert(hSocket != INVALID_SOCKET);

  SOCKADDR_IN RemoteSockAddr;
  RemoteSockAddr.sin_family = AF_INET;
  RemoteSockAddr.sin_port = htons((u_short)Port);
  RemoteSockAddr.sin_addr.s_addr = Ip;

  return ::connect(hSocket, (sockaddr *)&RemoteSockAddr, sizeof(RemoteSockAddr)) != SOCKET_ERROR;
}

bool BaseSOCKET::Connect(const char *pServerName, int Port)
{
  assert(hSocket != INVALID_SOCKET);

  DWORD Ip;
  if(!GetIpAddr(pServerName, &Ip))
    return false;
  return Connect(Ip, Port);
}

bool BaseSOCKET::GetIpAddr(const char *pName, DWORD *pIp)
{
  hostent *pHostent = ::gethostbyname(pName);
  if(pHostent == NULL)
    return false;
  *pIp = ((LPIN_ADDR)pHostent->h_addr)->s_addr;
  return true;
}

bool BaseSOCKET::ConnectEx(DWORD Ip, int Port, int TimeoutMilliSeconds)
{
  if(!SetBlockingMode(false))
    return false;

  if(!Connect(Ip, Port) && WSAGetLastError() != WSAEWOULDBLOCK)
    return false;

  if(!WaitData(false, TimeoutMilliSeconds))
    return false;

  if(!SetBlockingMode(true))
    return false;
  return true;
}

bool BaseSOCKET::ConnectEx(const char *pServerName, int Port, int TimeoutMilliSeconds)
{
  assert(hSocket != INVALID_SOCKET);

  DWORD Ip;
  if(!GetIpAddr(pServerName, &Ip))
    return false;
  return ConnectEx(Ip, Port, TimeoutMilliSeconds);
}

bool BaseSOCKET::Bind(int Port, const char *pSocketAddress)
{
  assert(hSocket != INVALID_SOCKET);

  SOCKADDR_IN LocalSockAddr;
  memset(&LocalSockAddr, 0, sizeof(LocalSockAddr));

  LocalSockAddr.sin_family = AF_INET;
  if(pSocketAddress == NULL)
    LocalSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  else
  {
    DWORD Result = inet_addr(pSocketAddress);
    if (Result == INADDR_NONE)
      return false;
    LocalSockAddr.sin_addr.s_addr = Result;
  }
  LocalSockAddr.sin_port = htons(Port);
  return ::bind(hSocket, (struct sockaddr FAR *)&LocalSockAddr, sizeof(LocalSockAddr)) != SOCKET_ERROR;
}

// �첽ѡ��
bool BaseSOCKET::AsyncSelect(HWND hWnd, UINT Msg, long Event)
{
  assert(hSocket != INVALID_SOCKET);
  if(!::IsWindow(hWnd) || Msg == 0)
    return false;

  return ::WSAAsyncSelect(hSocket, hWnd, Msg, Event) != SOCKET_ERROR;
}

// �¼�ѡ��
bool BaseSOCKET::EventSelect(WSAEVENT hEvent, long NetworkEvents)
{
  assert(hSocket != INVALID_SOCKET);
  return ::WSAEventSelect(hSocket, hEvent, NetworkEvents) != SOCKET_ERROR;
}

// ���ر��ض˿ںš� ��������򷵻� -1
int BaseSOCKET::GetLocalPort()
{
  assert(hSocket != INVALID_SOCKET);

  SOCKADDR_IN LocalSockAddr;
  int Len = sizeof(LocalSockAddr);
  if(getsockname(hSocket, (sockaddr *)&LocalSockAddr, &Len) == SOCKET_ERROR)
    return -1;   // Error

  return ntohs(LocalSockAddr.sin_port);
}

// ����Զ�˶˿ںš� ��������򷵻� -1
int BaseSOCKET::GetRemotePort()
{
  assert(hSocket != INVALID_SOCKET);

  SOCKADDR_IN RemoteSockAddr;
  int Len = sizeof(RemoteSockAddr);
  if(getpeername(hSocket, (sockaddr *)&RemoteSockAddr, &Len) == SOCKET_ERROR)
    return -1;   // Error

  return ntohs(RemoteSockAddr.sin_port);
}

// ȡ�ñ���������
bool BaseSOCKET::GetLocalHostName(char *pHostNameBuf, int BufSize) // static
{
  assert(pHostNameBuf != NULL);
  if(pHostNameBuf == NULL)
    return false;

  return ::gethostname(pHostNameBuf, BufSize) != SOCKET_ERROR;
}

// ȡ��Զ��������
bool BaseSOCKET::GetRemoteHostName(char *pHostNameBuf, int BufSize)
{
  assert(hSocket != INVALID_SOCKET);
  assert(pHostNameBuf != NULL);
  if(pHostNameBuf == NULL)
    return false;

  SOCKADDR_IN RemoteSockAddr;
  int Len = sizeof(RemoteSockAddr);
  if(getpeername(hSocket, (sockaddr *)&RemoteSockAddr, &Len) == SOCKET_ERROR)
    return false;   // Error

  hostent *pHostent = gethostbyaddr((char *)&RemoteSockAddr.sin_addr.s_addr, 4 ,PF_INET);
  if(pHostent == NULL)
    return false;

  lstrcpyn(pHostNameBuf, pHostent->h_name, BufSize);
  return true;
}

bool BaseSOCKET::GetLocalIpStatic(char *pStrIpBuf, int BufSize) // static 
{
  char  HostName[128];
  if(gethostname(HostName, sizeof(HostName)) != 0)
    return false;

  HOSTENT *pHost = gethostbyname(HostName);
  if(pHost == NULL)
    return false;
   
  char *pIpStr = inet_ntoa(*(in_addr*)pHost->h_addr_list[0]);
  if(pIpStr == NULL)
    return false;

  lstrcpyn(pStrIpBuf, pIpStr, BufSize);
  return true;
}

// ȡ�ñ��� IP ��ַ
bool BaseSOCKET::GetLocalIp(char *pStrIpBuf, int BufSize)
{
  assert(hSocket != INVALID_SOCKET);
  assert(pStrIpBuf != NULL);
  if(pStrIpBuf == NULL)
    return false;

  SOCKADDR_IN LocalSockAddr;
  int Len = sizeof(LocalSockAddr);
  if(getsockname(hSocket, (sockaddr *)&LocalSockAddr, &Len) == SOCKET_ERROR)
    return false;   // Error

  LongToDotIp(LocalSockAddr.sin_addr.s_addr, pStrIpBuf, BufSize);
  return true;
}

// ȡ��Զ�� IP ��ַ
bool BaseSOCKET::GetRemoteIp(char *pStrIpBuf, int BufSize)
{
  assert(pStrIpBuf != NULL);
  assert(hSocket != INVALID_SOCKET);
  if(pStrIpBuf == NULL)
    return false;

  SOCKADDR_IN RemoteSockAddr;
  int Len = sizeof(RemoteSockAddr);
  if(getpeername(hSocket, (sockaddr *)&RemoteSockAddr, &Len) == SOCKET_ERROR)
    return false;   // Error

  LongToDotIp(RemoteSockAddr.sin_addr.s_addr, pStrIpBuf, BufSize);
  return true;
}

}

