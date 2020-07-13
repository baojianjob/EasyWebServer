//***********************************************
// ��������: ISAPI Cookie ��ʾ
// ��������: baojian 2008.5.19
// ������ʷ: 
//***********************************************

#include "stdafx.h"
#include "HttpParse.h"

BOOL WINAPI GetExtensionVersion(OUT HSE_VERSION_INFO *pVer)
{
    pVer->dwExtensionVersion = MAKELONG(HSE_VERSION_MINOR, HSE_VERSION_MAJOR);
    strcpy(pVer->lpszExtensionDesc, "IsaCookie");
    return TRUE;
}

DWORD WINAPI HttpExtensionProc(IN EXTENSION_CONTROL_BLOCK *pECB)
{
    // Parse
    CHttpContext HttpCtx(pECB);
    if(!HttpCtx.ParseHttpData())
        return HSE_STATUS_ERROR;

    // get cookie
    int Count = 0;
    const char *pCount = HttpCtx.GetCookieList().GetValueByName("count");
    if(pCount && *pCount)
        Count = atoi(pCount);

    // add
    Count++;

    // response header
    char TempStr[1024];
    sprintf(TempStr, "%d", Count);
    time_t CurTime = 0;
    time(&CurTime);
    HttpCtx.SetCookie("count", TempStr, CurTime + 3600); // expire in 1 hours
    HttpCtx.AddHeader("Content-Type: text/html");
    HttpCtx.SendResponseHeader();

    // data
    char ResultStr[1024];
    DWORD Len = sprintf(ResultStr, "<html><head><title>Isapi Cookie ��ʾ</title></head>\r\n<body>��������%d�������ҳ��</body></html>", Count);
    HttpCtx.WriteClient(ResultStr, Len);

    return HSE_STATUS_SUCCESS;
}

BOOL WINAPI TerminateExtension(IN DWORD dwFlags)
{
    return TRUE;
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
    return TRUE;
}