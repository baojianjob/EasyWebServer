#ifndef __WEBSVR_H__
#define __WEBSVR_H__
#pragma once

#include <httpext.h>
#include "baseio.h"
#include "tlist.h"
#include "strlist.h"
#include "CritSect.h"
#include "netsvr.h"

using namespace minilib;
/*
http://wbj/cgi1.exe/abc?def
/cgi1.exe/abc?def
SCRIPT_NAME=/cgi1.exe
PATH_INFO=/abc
PATH_TRANSLATED=e:\inetpub\wwwroot\abc
QUERY_STRING=def
*/
class CRequestData
{
public:
    BOOL        bValidate;              // http�����Ƿ���Ч(�Ƿ�����ɹ�)
    MtSTRING    RequestMethod;          // ���󷽷� GET/POST/HEAD
    MtSTRING    WebFileName;            // ��ҳ�ļ���
    MtSTRING    ScriptName;
    MtSTRING    LocalFileName;          // ת����ı����ļ���
    MtSTRING    PathInfo;
    DWORD       ContentLength;  
    MtSTRING    QueryString;
    MtSTRING    CookieString;
    MtSTRING    ContentType;
    MtSTRING    SoapAction;
    MtSTRING    HostName;
    MtSTRING    UserAgent;
    MtSTRING    Referer;
    MtSTRING    Authorization;
    BYTE       *pRawData;
    DWORD       RawDataLen;
    BYTE       *pContentData;

    SYSTEMTIME  IfModifiedSince;        // If-Modified-Since
    __int64     RangeBegin;
    __int64     RangeEnd;
    BYTE        bIfModifiedSinceValid;  // ָ��IfModifiedSince�Ƿ���Ч
    BYTE        bRangeValid;            // ָ��RangeBegin��RangeEnd�Ƿ���Ч
    BYTE        bKeepAlive;             // KeepAlive
    BYTE        Reserve;                // ����

public:
    CRequestData();
    ~CRequestData();

public:
    void        SetEmpty();
};

enum HttpACT
{
    HTTP_ACT_SENDFILE,
    HTTP_ACT_EXECUTE,
    HTTP_ACT_BROWSEDIR,
};

#define MAX_ENGINE_EXTNAME 32

class CScriptEngine
{
public:
    MtSTRING    ExtName;
    MtSTRING    CommandLine;

public:
    CScriptEngine() {};
    CScriptEngine(const MtSTRING &Name, const MtSTRING &Path) : ExtName(Name), CommandLine(Path) {}
    bool operator==(const CScriptEngine &Other) const { return ExtName.CompareNoCase(Other.ExtName) == 0; }
};
typedef TLIST<CScriptEngine> EngineLIST;

class CWebServerConfig
{
public:
    MtSTRING    RootDirectory;    // ��Ŀ¼
    StrLIST     DefaultDoclList;  // ȱʡ�ĵ��б�
    int         ListenPort;       // �˿ں�
    int         MaxThreadNum;     // �����������0��ʾ�����ƣ�
    BOOL        bEnableCgi;       // �Ƿ�����ִ��CGI
    BOOL        bEnableIsapi;     // �Ƿ�����ִ��ISAPI
    BOOL        bEnableScript;    // �Ƿ�����ִ�нű�
    BOOL        bIsapiCache;      // ����ISAPI(����bEnableIsapiΪTRUEʱ��Ч)
    int         NetTimeout;       // ��ʱʱ�䣨��λ1/1000�룩
    BOOL        bAutoRun;         // �Ƿ񿪻��Զ�����
    BOOL        bIconStartStop;   // �Ƿ������ͼ������ֹͣ������
    BOOL        bEnableShowDir;   // �Ƿ�����Ŀ¼���
    BOOL        bShowDirAlways;   // �Ƿ�������ʾĿ¼����(����bEnableShowDirΪTRUEʱ��Ч)
    BOOL        bLogToWindow;     // ��¼��־������
    int         LogWndMaxLine;    // ��־���������ʾ����(����bLogToWindowΪTRUEʱ��Ч)
    BOOL        bLogToFile;       // ��¼��־���ļ�
    MtSTRING    LogFileName;      // ��־�ļ���(����bLogToFileΪTRUEʱ��Ч)
    MtSTRING    ServerName;       // ����������/�汾
    DWORD       MaxContentLength; // ���յ����ContentLength
    DWORD       MaxHeaderLength;  // ���յ����HeaderLength��\r\n\r\n֮ǰ�ģ�
    EngineLIST  ScriptEngineList; // �ű������б�

public:
    CWebServerConfig();

public:
    void        SetDefaultHtmlList(const TCHAR *pDefaultHtmlStr);
    void        GetDefaultHtmlStr(MtSTRING &DefaultHtmlStr) const;
};

typedef BOOL (WINAPI *GetExtensionVersionFUNC)(HSE_VERSION_INFO *pVersion);
typedef DWORD (WINAPI *HttpExtensionProcFUNC)(EXTENSION_CONTROL_BLOCK *pECB);
typedef BOOL (WINAPI *TerminateExtensionFUNC)(DWORD dwFlags);

struct CCacheDllData
{
    MtSTRING                    DllFileName;
    HMODULE                     hDll;
    GetExtensionVersionFUNC     pGetExtensionVersion;
    HttpExtensionProcFUNC       pHttpExtensionProc;
    TerminateExtensionFUNC      pTerminateExtension;
};

typedef TLIST<CCacheDllData> CacheDllLIST;
typedef CacheDllLIST::POSITION CacheDllListPOS;

enum HTTP_ERROR
{
    HERROR_SUCCESS,
    HERROR_NETWORK,         // ��ȡHttp����ʱ�������
    HERROR_CONTENTLENGTH,   // ��ȡHttp����ʱContentLength̫��
    HERROR_HEADERLENGTH,    // ��ȡHttp����ʱHeader̫��
    HERROR_BADREQUEST,      // ��Ч��Http����
    HERROR_FORBIDDEN,       // Http�����Url�к���..��
    HERROR_BADISAPI,        // �����ISAPI dll
    HERROR_EXCEPTION,       // ISAPIִ���׳��쳣�򷵻�ʧ��
};

class CWebServer;
class CWebServerThread : public CServerThread
{
public:
    CRequestData    RequestData;
    BOOL            bResponseKeepAlive;
    EXTENSION_CONTROL_BLOCK *pECB;

public:
    CWebServerThread() { bResponseKeepAlive = FALSE; pECB = NULL; };
    ~CWebServerThread() { delete pECB; };
    BaseSOCKET   &GetSocket();
    CWebServer    *GetWebServer();
    const SOCKADDR_IN &GetClientAddr();

protected:
    virtual int   ServerProc();

    HTTP_ERROR      ReadRequest(CRequestData &RequestData, int TimeOutMilliSeconds, int GrowBy);
    HTTP_ERROR      ParseRequest(CRequestData &RequestData);
    BOOL            ProcessRequest(CRequestData &RequestData, const MtSTRING &WebFileName, BOOL &bExecute);
    BOOL            SendHttpFile();
    BOOL            SendHttpErrorStr(const TCHAR *pResponseCmd, const TCHAR *pResponseText);
    const TCHAR    *GetFileContentType(const TCHAR *pFileExtName);
    void            BuildCgiEnvironment(const CRequestData &RequestData, MemFILE2 &MemFile);
    BOOL            ExecuteCgiProcess(const CRequestData &RequestData);
    HTTP_ERROR      ExecuteIsapiDll(const CRequestData &RequestData);
    const TCHAR    *GetExistDefaultHtml(MtSTRING &LocalFilePath, const StrLIST &DefaultDoclList);
    BOOL            BrowseDirectory(const TCHAR *pWebDirName, const TCHAR *pLocalDirName);
    BOOL            ParseDateTime(TCHAR *pTimeStr, SYSTEMTIME &Time);
    BOOL            ParseWeekDay(const TCHAR *pToken, WORD &nWeekDay);
    BOOL            ParseMonth(const TCHAR *pToken, WORD &nMonth);
    BOOL            ParseRange(TCHAR *pRangeStr, __int64 &RangeBegin, __int64 &RangeEnd);

    friend void ReadPipeFunc(HANDLE hPipe, LPARAM FuncParam);
};

inline BaseSOCKET &CWebServerThread::GetSocket()
{
    return TheSocket;
}

inline const SOCKADDR_IN &CWebServerThread::GetClientAddr()
{
    return ClientAddr;
}

//////////////////////////////////////////////////////////////////////////

class CWebServer : public CNetServer
{
public:
    CWebServer();
    ~CWebServer();

public:
    BOOL          Init(const CWebServerConfig &Config);
    const CWebServerConfig &GetServerConfig();

protected:
    virtual CServerThread *CreateServerThread();
    virtual void  OnServerStarted();
    virtual void  OnServerClosed();
    virtual void  OnServerTimestep();
    virtual void  OnRequestLog(const SOCKADDR_IN &ClientAddr, const CRequestData &RequestData, BOOL bExecute, BOOL bSuccess);

    const CCacheDllData *FindCacheDll(const TCHAR *pDllFileName);
    void          AddOneCacheDll(const CCacheDllData &CacheDllData);

protected:
    CWebServerConfig ServerConfig;  // ����������
    CacheDllLIST  CacheDllList;     // ISAPI��dll����
    CCriticalSect CacheDllListCs;

    friend class CWebServerThread;
};

inline CServerThread *CWebServer::CreateServerThread()
{
    return new CWebServerThread;
}

inline const CWebServerConfig &CWebServer::GetServerConfig()
{
    return ServerConfig;
}

inline CWebServer *CWebServerThread::GetWebServer()
{
    return (CWebServer *)pServer;
}

//////////////////////////////////////////////////////////////////////////

BOOL ParseEngineCommandLine(const MtSTRING &CommandLine, MtSTRING &EnginePath, MtSTRING &EngineParam);

#endif // __WEBSVR_H__