#ifndef __NETSVR_H__
#define __NETSVR_H__
#pragma once

#include "socket.h"
#include "thread.h"
#include "mtstring.h"

using namespace minilib;

class CNetServer;

class CServerThread : public CBaseThread
{
protected:
    BaseSOCKET    TheSocket;
    SOCKADDR_IN   ClientAddr;
    int           ClientAddrLen;
    CNetServer   *pServer;
    BOOL          bDeleteThis;

public:
    CServerThread();
    ~CServerThread();

protected:
    virtual int   ServerProc();

private:
    virtual int   RunProc(); 

    friend class CNetServer;//::RunProc(); 
};

class CNetServer : protected CBaseThread
{
public:
    CNetServer();
    virtual ~CNetServer();

public:
    BOOL                Init(int Port, int MaxThreadNum = 50);
    BOOL                StartServer();
    BOOL                StopServer();
    BOOL                IsServerRunning();

    LONG                GetClientThreadNum();
    const TCHAR        *GetLastErrStr();

protected:
    virtual CServerThread *CreateServerThread();
    virtual void        OnServerStarted() {};
    virtual void        OnServerClosed() {};
    virtual void        OnServerTimestep() {};

protected:
    BaseSOCKET          ListenSocket;   // ������Socket
    UINT                ListenPort;     // �����Ķ˿�
    WSAEVENT            hEventSocket;   // socket�¼�
    WSAEVENT            hEventExit;     // �˳��¼�
    MtSTRING            LastErrStr;     // ����ԭ������
    volatile LONG       ThreadNum;      // �߳���
    LONG                MaxThreadNum;   // ����߳���
    UINT                WaitTimestep;   // 

private:
    virtual int   RunProc(); 

    friend class CServerThread;
};

inline const TCHAR *CNetServer::GetLastErrStr()
{
    return (LPCTSTR)LastErrStr;
}

inline LONG CNetServer::GetClientThreadNum()
{
    return ThreadNum;
}

inline BOOL CNetServer::IsServerRunning()
{
    return ListenSocket.IsValidSocket();
}

#endif // __NETSVR_H__