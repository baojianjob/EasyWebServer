#include "stdafx.h"
#include "mywebsvr.h"

CMyWebServer::CMyWebServer()
{
}

BOOL CMyWebServer::Init(const CWebServerConfig &Config)
{
    if(!CWebServer::Init(Config))
        return FALSE;
    SvrLog.bLogToWnd = Config.bLogToWindow;
    SvrLog.bLogToFile = Config.bLogToFile;
    SvrLog.ListBoxLog.SetListBoxWnd(SvrLog.ListBoxLog.GetListBoxWnd(), Config.LogWndMaxLine);
    if(SvrLog.bLogToFile)
        SvrLog.FileLog.SetLogFileName(Config.LogFileName);
    return TRUE;
}

void CMyWebServer::OnRequestLog(const SOCKADDR_IN &ClientAddr, const CRequestData &RequestData, 
                               BOOL bExecute, BOOL bSuccess)
{
    if(!ServerConfig.bLogToWindow && !ServerConfig.bLogToFile)
        return;

    MtSTRING LogText;
    if(RequestData.bValidate)
    {
        LogText.Format(_T("[%s] %s %s %s"), inet_ntoa(ClientAddr.sin_addr),
            bExecute ? _T("ִ��") : (LPCTSTR)RequestData.RequestMethod, (LPCTSTR)RequestData.WebFileName, 
            bSuccess ? _T("�ɹ�") : _T("ʧ��"));
    }
    else
    {
        LogText.Format(_T("[%s] ��Ч��HTTP����"), inet_ntoa(ClientAddr.sin_addr));
    }

    SvrLog.AddLog(LogText, TRUE);
    SvrLog.SetListBoxMaxTextLen(LogText.GetLength());
}
