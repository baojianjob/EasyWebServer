// ��ʱ�࣬��Ҫ���ڲ��Գ���Ĳ��ֻ�ȫ����������м�
// wbj 2002.12.26
// wbj 2004.7.1

#ifndef __CALTIME_H__
#define __CALTIME_H__

namespace minilib
{

#define MAX_CALTIME_STRLEN      256

class CalTIME
{
public:
  CalTIME();
  ~CalTIME();
  
  void          BeginCountTime();       // ��ʼ��ʱ
  void          EndCountTime();         // ������ʱ
  void          ReSetZeroTime();        // ��ԭ
  
  void          GetTotalTime(SYSTEMTIME &TotalSysTime);
  void          GetTotalTime(DWORD &TotalMilliSec);
  const TCHAR  *GetTotalTimeStr(const TCHAR *pItemName);
  BOOL          WriteFileLog(const TCHAR *pFileName, const TCHAR *pItemName, const TCHAR *pSep = _T("\r\n"));

#ifdef WIN32
  void PopMessage(HWND hWnd, const TCHAR *pName);
#endif

private:
  DWORD         TotalTime;              // �ܹ����ѵ�ʱ�䣬�� 1/1000 ���
  DWORD         BeginTime;              // ������� BeginCountTime() ʱ��ʱ�䣬�� 1/1000 ���
  TCHAR         TimeStr[MAX_CALTIME_STRLEN];
};

inline CalTIME::CalTIME()
{
  TotalTime = 0;
  memset(TimeStr, 0, sizeof(TimeStr));
}

inline CalTIME::~CalTIME()
{
}

inline void CalTIME::BeginCountTime()
{
  BeginTime = ::GetTickCount();
}

inline void CalTIME::EndCountTime()
{
  TotalTime += ::GetTickCount() - BeginTime;
}

inline void CalTIME::ReSetZeroTime()
{
  TotalTime = BeginTime = 0;
}

inline void CalTIME::GetTotalTime(SYSTEMTIME &TotalSysTime)
{
  ::memset(&TotalSysTime, 0, sizeof(SYSTEMTIME));

  TotalSysTime.wMilliseconds = (WORD)(TotalTime % 1000);
  TotalSysTime.wSecond = (WORD)(TotalTime / 1000L % 60);
  TotalSysTime.wMinute = (WORD)(TotalTime / 60000L % 60);
  TotalSysTime.wHour = (WORD)(TotalTime / 3600000L % 24);
}

inline void CalTIME::GetTotalTime(DWORD &TotalMilliSec)
{
  TotalMilliSec = TotalTime;
}

inline const TCHAR *CalTIME::GetTotalTimeStr(const TCHAR *pItemName)
{
  lstrcpyn(TimeStr, pItemName, MAX_CALTIME_STRLEN - 50);

  wsprintf(TimeStr + lstrlen(TimeStr), _T(": %d.%03d ��"), 
    TotalTime / 1000, TotalTime % 1000);
  return TimeStr;
}

inline void CalTIME::PopMessage(HWND hWnd, const TCHAR *pItemName)
{
  MessageBox(hWnd, GetTotalTimeStr(pItemName), _T("���м�ʱ"), MB_ICONINFORMATION);
}

inline BOOL CalTIME::WriteFileLog(const TCHAR *pFileName, const TCHAR *pItemName, const TCHAR *pSep)
{
  FILE *pFile = _tfopen(pFileName, _T("ab"));
  if(pFile == NULL)
    return FALSE;

  //_fputts(GetTotalTimeStr(pItemName), pFile);
  const TCHAR *pStr = GetTotalTimeStr(pItemName);
  fwrite(pStr, sizeof(TCHAR), lstrlen(pStr), pFile);
  fwrite(pSep, sizeof(TCHAR), lstrlen(pSep), pFile);

  fclose(pFile);
  return TRUE;
}

///////////////////////////////////////////////////////////////////////////////

class FuncTimeTEST
{
public:
  FuncTimeTEST(const TCHAR *pFileName, const TCHAR *pItemName, const TCHAR *pSep = _T("\r\n"))
  {
    this->pFileName     = pFileName;
    this->pItemName     = pItemName;
    this->pSep          = pSep;

    T.BeginCountTime();
  }
  ~FuncTimeTEST()
  {
    T.EndCountTime();
    T.WriteFileLog(pFileName, pItemName, pSep);
  }

protected:
  CalTIME       T;
  const TCHAR  *pFileName;
  const TCHAR  *pItemName;
  const TCHAR  *pSep;
};

}

#endif // __CALTIME_H__