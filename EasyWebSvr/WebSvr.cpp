/*
���ܣ� Web������

���Ľ���
1. ִ��CGI��������ʱ��
2. ���Խ��ա�������ִ�С����͡���־��ʱ�䣬���Ч��
3. ����Ŀ¼
4. ��������
5. ����RecvError������Reset
6. ���������־ListBox��Ч��
7. ���ý���tab����������Bug
8. ���Ǻ�׺��Ϊ.cgi��CGI����
9. ���wsprintf,strcpy�ȿ��ܵĻ��������
10. CGI�������������Ĵ���
11. ���� ����%20README ��������Bug
12. ֧��cgi/isapi�����ң���������
13. ��Win98�²���
14. ���ơ����ڡ�����
15. �������ʵ��������
16. ����httpЭ��ı�׼�ԣ���IIS���Ա�
17. ֧��HTTPS SSL
18. ��ֹ��cgi/isapi�����е���MessageBox
19. ISAPI Location��ҳ�ض���
20. ������Ŀ¼Ϊ���·��
21. POST��ͨ�ļ�ʱ����ʾ405 Method Not Allowed

����cgi�ϴ�/���ش��ļ�
������룬���Ч��
��־��Ϊ���ش��룬���ǳɹ�/ʧ��
���øı�󣬱�Ҫ����ʱ������
url�к���\n��Bug
������ɫ��ˢ������
֧���û���Ȩ��֤
��ʾĿ¼�б�ʱ�����⣨Content-Length��
֧��web������ģʽ


������ʷ��
==========
ab.exe��������
����Ŀ¼���ʱ�Ժ��ֱ���
isapi keepalive
���ƽ�
�ű�ӳ��ʱ�������ö�exe��dll��ӳ��
�ĵ�����ʾĿ¼���ʱ����Ҫѡ��ִ��Ȩ��
�����cgi/isapi�������cgi-binĿ¼

2.0�湦�� --�ƻ�
1. ֧��ISAPI������
2. ����CGIִ��ʱ��
3. ֧��ISAPI����Pending
4. ������������������
5. ѹ�����з�ISAPIʾ��Դ��

2007.11.14
1. ISAPIִ���쳣ʱ��Connection����Ϊclose
2. ����ĳЩCGI�������ִ�в�������Bug���ֶ�����ͷ��
3. �����ĵ������ԣ�����EasyWebServer1.9

2007.11.13
1. ��ʾĿ¼�б�ʱ�����ļ���Ŀ¼����
2. ����Ŀ¼�б�ҳ����ĳЩ���ع��߲������ص�Bug��URL���룩

2007.11.12
1. ����CGI��Status��Location��
2. �ű�ӳ������Ӧ�ó����������
3. ����ʵ���˶�Perl��֧�֣�CGI��perl.exe��!

2007.11.10
1. ����ʵ�ֶ�KeepAlive�־����ӹ��ܵ�֧��
2. ���������̲˵����Ե���������ô��ڵ�Bug

2007.11.8
ʵ�ֽű�ӳ�书�ܼ��������ã�����֧��ASP�ˣ�ʹ��ActiveHTML��������!

2007.11.6
1. ����������ύ�����HttpHeader��С����������
2. ����CGI/ISAPIִ��ʧ��ʱ��Httpͷ��Ϣ
3. ʵ�ֶ�HTTP��HEAD�����֧��
4. �����ĵ������ԣ�����EasyWebServer1.8

2007.11.5
1. ����ISAPI����������UserAgent��Referer��Authorization��
2. ���������Զ����в������ܱ����Bug
3. ����������ύ�����Content-Length��С����������

2007.10.21
1. ���ƶ�ISAPI��֧�֣�ResponseHeader��TerminateExtension��
2. ʵ�ֶ�ISAPI��PHP��֧�֣���ȫ��֧��PHP��!!!
3. �����־������ļ�ʱ��Ч��
4. �����ĵ������ԣ�����EasyWebServer1.7

2007.10.12
1. ���Ӷ�ISAPI��ת���ܵ�֧��
2. ������ĳЩ��������½�����ɫ��ʾ������������

2006.5.19
1. ֧��.cgi��չ����cgi������ʵ��.exe��ͬ��
2. ������demo�е�isapi1.dll��ĳЩ�����в������е�Bug
3. �����ĵ������ԣ�����EasyWebServer1.6

2006.5.18
1. ʵ��֧��PHP���ܵ����ý���
2. ������������Դ������������ͼ��״̬��ʾ�����Bug

2006.5.17
ʵ������ http://wbj/cgi ��URL��ת�� http://wbj/cgi/

2006.5.12
1. �����˶�ʹ���ض����ܵ�php�������в�������Bug
2. ��������Firefox������¶�ʹ�õ���css�ļ�����ҳ��ʾ��������Bug

2006.5.10
����ʵ���˶�PHP��֧�֣�cgi��php4��

2006.3.30
������ʹ��Opera�����Cookie��������Bug

2006.3.11
���ƹ��ڽ��桢�ĵ�
���ԣ�����EasyWebServer1.5

2006.3.10
1. �ػ����˳�ʱ���洰��״̬������������״̬
2. ���������к�ֹͣʱ�����ò�ͬ������ͼ��

2006.3.9
1. ���Ƴ���ICON
2. ���������ҳ�Ĺ���

2006.3.8
������ISAPI�Ĳ��ֻ�������

2006.3.7
1. ʵ���˶��ļ����ضϵ�������֧�֣�Range��Content-Range��ǣ�
2. ����tooltips������״̬��ʾ

2006.3.6
ʵ���˶�HTTP��Last-Modified��If-Modified-Since��֧��

2006.3.5
�����ļ����طֶη���

2006.3.3
1. ��дHTTP����Ľ�����̣�����CGI�������������ƹܵ����������˲���CGI�������в�������Bug
(����SCRIPT_NAME��PATH_INFO�Ȼ�������) http://wbj/cgi1.exe/aaa?bbb
2. ȱʡ����CGI/ISAPIȨ��

2006.2.22
1. ״̬�����ӿ��ư�ť�Ͳ˵���ť
2. �����˶Է���socket�����CGI�������в�������Bug
3. �޸����������ICON

2006.1.22
���ӿ����Զ����еĹ��ܣ�ע��������飩
����EasyWebServer1.0

2006.1.20
1. ʵ����ȱʡ�ĵ��б�Ĺ���
2. ������־���ù��ܣ���������ڣ�������ļ���

2006.1.19
ʵ���˶�����UTF-8�����֧��

2006.1.18
1. ʵ����Ŀ¼����Ĺ���
2. �����˿�����..Խ�����ʵ�Bug
3. ����ṹ��������д��url·��ת������ش���
4. ���Ӷԡ�����HTTP����ʧ�ܡ�����־��¼

2006.1.13
ʵ����ISAPI�Ļ���dll�Ĺ���

2006.1.12
1. ���������ش����������һ��ר�ŵ����ý��棬
   �ֶ��Tab����ҳ������[����]��[Ȩ��]��[�ĵ�]��[��־]
2. ���Ӷ��������������ʱʱ�������

2006.1.6
���ƽ��桢�ĵ��ȣ�����EasyWebServer V0.8

2005.12.31
�����˶�ISAPI����SOAP����������Bug

2005.12.30
1. ʵ���˶�ISAPI�����֧�֣�
2. ���ƽ������á���־��

2005.12.29
����ʵ����GDI���棬����С��ϵͳ����

2005.12.26
1. ʵ���˶�CGI����POST������֧�֣�
2. �����˶�URL���пո�Ȳ�������Bug

2005.12.24
1. �о���һ����CGI�ܵ���������ͷ���ۻ�ѽ��
   ƽ��ҹ23:00�����ڽ����ʵ��CGI֧�ֵĹؼ��������⣡
2. ��д��Http����Ľ���ģ�����

2005.12.22
����ʵ���˶�CGI����GET������֧��

2005.12.20
���棬ʵ���˶Ծ�̬��ҳ��֧��
*/

#include "stdafx.h"
#include "websvr.h"
#include "cmncode.h"
#include "resphdr.h"

#pragma warning(disable:4996)

#define WEBSERVER_NAME_VERSION  _T("EasyWebServer/1.92")  

#ifndef INVALID_FILE_ATTRIBUTES
    #define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
#endif

/* 
REQUEST_METHOD : GET/POST

GET: 
������ QUERY_STRING ����������

POST:
CONTENT_TYPE CONTENT_LENGTH

GET /aa.exe?aa=bb&cc=dd HTTP/1.1
Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-powerpoint, application/vnd.ms-excel, application/msword, * /*
Accept-Language: zh-cn
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; MyIE2; Maxthon; .NET CLR 1.0.3705)
Host: wbj:81
Connection: Keep-Alive
Cookie: ASPSESSIONIDGQGQQOBC=OHLHKCKAHNMNGLBKHFEEEDMP
*/

static int HexToInt(TCHAR ch)
{
    if((ch >= _T('0')) && (ch <= _T('9')))
        return ch - _T('0');

    if((ch >= _T('a')) && (ch <= _T('f')))
        return ch - _T('a') + 10;
    else if((ch >= _T('A')) && (ch <= _T('F')))
        return ch - _T('A') + 10;
    return -1;
}

//����˼·:
//  ����Դ�ַ������������+�����ɿո�
//  �������%xx����xx�����֣���ִ��16���ƽ���
//  ����xx�������һ������0x7F���ַ�Ҳ����0xE0������Ϊ��UTF8���룬��ִ��UTF8����
static void UrlDecode(char *&pSrcBuf, char *&pDestBuf, bool &bUtf8)
{
    assert(!bUtf8);

    bool bValid = false;
    for(; *pSrcBuf; pSrcBuf++, pDestBuf++)
    {
        if(*pSrcBuf != _T('%'))
        {
            //if(*pSrcBuf == _T('+'))
            //{
            //    *pDestBuf = _T(' ');
            //    continue;
            //}
        }
        else
        {
            if(pSrcBuf[1] && pSrcBuf[2])
            {
                int High = HexToInt(pSrcBuf[1]);
                int Low = HexToInt(pSrcBuf[2]);
                if(High != -1 && Low != -1)
                {
                    *pDestBuf = char((High << 4) + Low);
                    if(!bValid && ((BYTE)(*pDestBuf) > 0x7F))
                    {
                        bUtf8 = ((BYTE)(*pDestBuf)) > 0xE0;
                        bValid = true;
                    }
                        
                    pSrcBuf += 2;
                    continue;
                }
            }
        }
        *pDestBuf = *pSrcBuf;
    }
    *pDestBuf = 0;
}

static void UrlDecode(char *pUrlStr)
{
    char *pSrcBuf = pUrlStr, *pDestBuf = pUrlStr;
    for(; *pSrcBuf; pSrcBuf++, pDestBuf++)
    {
        if(*pSrcBuf != _T('%'))
        {
            //if(*pSrcBuf == _T('+'))
            //    *pDestBuf = _T(' ');
        }
        else
        {
            bool bUtf8 = false;
            UrlDecode(pSrcBuf, pDestBuf, bUtf8);
            if(bUtf8)
            {
                // ������ߴ˴�UTF8�����Ч�� ---------
                // UTF8 --> UNICODE
                int SrcLen = (int)strlen(pUrlStr);
                int WideLen = MultiByteToWideChar(CP_UTF8, 0, pUrlStr, SrcLen, NULL, NULL);
                assert(WideLen > 0);
                wchar_t *pWideStr = (wchar_t *)malloc(WideLen * sizeof(wchar_t));
                MultiByteToWideChar(CP_UTF8, 0, pUrlStr, SrcLen, pWideStr, WideLen);

                // UNICODE --> MultiByte
                int Len = WideCharToMultiByte(CP_ACP, 0, pWideStr, WideLen, pUrlStr, SrcLen, NULL, NULL);
                pUrlStr[Len] = 0;

                free(pWideStr);
            }
            break;
        }
    }
}

static void UrlDecode(MtSTRING &UrlStr)
{
    UrlDecode(UrlStr.GetBuffer(UrlStr.GetLength()));
    UrlStr.ReleaseBuffer();
}

/*
ֻҪ��ȡ��һ���ֽڲ��ж�����16���ƴ���0xE0�Ϳ�֪����UTF8��

(����):http://wbj/CGI�ĵ�.chm
(��):http://wbj/CGI%CE%C4%B5%B5.chm 
(UTF8):http://wbj/CGI%E6%96%87%E6%A1%A3.chm

(��):http://wbj/��������%20������˹�ж�%20Antitrust-CD1-Tlf.avi
(��):http://wbj/%B6%E1%C3%FC%C1%AC%CF%DF%20%B7%B4%CD%D0%C0%AD%CB%B9%D0%D0%B6%AF%20Antitrust-CD1-Tlf.avi
(UTF8):http://wbj/%E5%A4%BA%E5%91%BD%E8%BF%9E%E7%BA%BF%20%E5%8F%8D%E6%89%98%E6%8B%89%E6%96%AF%E8%A1%8C%E5%8A%A8%20Antitrust-CD1-Tlf.avi

http://wbj/CGI�ĵ�.chm

utf-8��ʽ����:
GET /CGI%E6%96%87%E6%A1%A3.chm HTTP/1.1

��utf-8��ʽ����:
GET /CGI�ĵ�.chm HTTP/1.1
*/

CRequestData::CRequestData()
{
    pRawData              = NULL;
    RawDataLen            = 0;
    ContentLength         = 0;
    pContentData          = NULL;
    bValidate             = FALSE;
    bIfModifiedSinceValid = FALSE;
    RangeBegin            = 0;
    RangeEnd              = 0;
    bRangeValid           = FALSE;
    bKeepAlive            = FALSE;
}

CRequestData::~CRequestData()
{
    if(pRawData != NULL)
        free(pRawData);
}

void CRequestData::SetEmpty()
{
    bValidate   = FALSE;
    bIfModifiedSinceValid = FALSE;
    bRangeValid = FALSE;
    bKeepAlive  = FALSE;

    RequestMethod.Empty();
    WebFileName.Empty();  
    ScriptName.Empty();
    LocalFileName.Empty();
    PathInfo.Empty();
    QueryString.Empty();
    CookieString.Empty();
    ContentType.Empty();
    SoapAction.Empty();
    HostName.Empty();
    UserAgent.Empty();
    Referer.Empty();
    Authorization.Empty();

    if(pRawData != NULL)
    {
        free(pRawData);
        pRawData = NULL;
    }
    RawDataLen    = 0;
    pContentData  = NULL;
    ContentLength = 0;
}

static void SkipChars(char *&pStr, char *pChars)
{
    assert(pStr != NULL && pChars != NULL && *pChars != 0);
    while(*pStr && strchr(pChars, *pStr) != NULL)
    {
        pStr++;
    }
}

HTTP_ERROR CWebServerThread::ReadRequest(CRequestData &RequestData, int TimeOutMilliSeconds, int GrowBy)
{
    assert(RequestData.pRawData == NULL && RequestData.RawDataLen == 0);
    assert(RequestData.pContentData == NULL && RequestData.ContentLength == 0);
    assert(GrowBy >= 2);

    BOOL bFoundEndFlag = FALSE;

    int ContentDataIndex = -1;

    DWORD AllocLen = 0;
    while(1)
    {
        if(AllocLen - RequestData.RawDataLen <= 1)
        {
            if(RequestData.ContentLength > 0)
            {
                assert(ContentDataIndex >= 0);
                assert(AllocLen < ContentDataIndex + RequestData.ContentLength + 1);
                AllocLen = ContentDataIndex + RequestData.ContentLength + 1;
            }
            else
                AllocLen += GrowBy;

            RequestData.pRawData = (BYTE *)realloc(RequestData.pRawData, AllocLen);
        }

        int Ret = TheSocket.Receive((char *)RequestData.pRawData + RequestData.RawDataLen, 
            AllocLen - RequestData.RawDataLen - 1);
        if(Ret == 0)
        {
            // �ͻ��������Ͽ�
            LOG_INFO(GID_WEBSERVER, "Network error, closed.");
            return HERROR_NETWORK;
        }
        else if(Ret < 0)
        {
            if(Ret == SOCKET_ERROR)
            {
                int Err = WSAGetLastError();
                if(Err == WSAEWOULDBLOCK)
                {
                    if(!TheSocket.WaitData(true, TimeOutMilliSeconds))
                    {
                        // ������ģʽ�ĳ�ʱ
                        LOG_INFO(GID_WEBSERVER, "Network error, timeout.");
                        return HERROR_NETWORK;
                    }
                    continue;
                }
                else if(Err == WSAETIMEDOUT)
                {
                    assert(false); // ������Ӧ��ֻ���ڷ�����ģʽ
                    // ����ģʽ�ĳ�ʱ
                    LOG_INFO(GID_WEBSERVER, "Network error, timeout.");
                    return HERROR_NETWORK;
                }
                else
                {
                    // �������� 
                    // ���ֳ����� 10054����  WSAECONNRESET
                    LOG_INFO(GID_WEBSERVER, "Network error, ErrID=%d.", Err);
                    return HERROR_NETWORK;
                }
            }
            else
            {
                assert(false);
                LOG_INFO(GID_WEBSERVER, "Network error, unknown.");
                return HERROR_NETWORK; 
            }
        }

        RequestData.RawDataLen += Ret;
        RequestData.pRawData[RequestData.RawDataLen] = '\0';

        if(!bFoundEndFlag)
        {
            char *pEndFlag = strstr((char *)RequestData.pRawData, "\r\n\r\n");
            if(pEndFlag != NULL)
            {
                bFoundEndFlag = TRUE;
                ContentDataIndex = (int)(pEndFlag + 4 - (char *)RequestData.pRawData);

                // �ض�
                pEndFlag[0] = '\0'; 

                // �� "Content-Length"
                char *pLine = (char *)RequestData.pRawData;
                while(1)
                {
                    if(strnicmp(pLine, "Content-Length", 14) == 0)
                    {
                        pLine += 14;
                        SkipChars(pLine, " :");
                        RequestData.ContentLength = atoi(pLine);
                        break;
                    }
                    pLine = strstr(pLine, "\r\n");
                    if(pLine == NULL)
                        break;
                    pLine += 2;
                }
                if(RequestData.ContentLength <= 0)
                    return HERROR_SUCCESS;
                if(RequestData.ContentLength > this->GetWebServer()->GetServerConfig().MaxContentLength)
                    return HERROR_CONTENTLENGTH;
            }
            else if(RequestData.RawDataLen > this->GetWebServer()->GetServerConfig().MaxHeaderLength)
                return HERROR_HEADERLENGTH;
        }

        if(RequestData.ContentLength > 0)
        {
            assert(bFoundEndFlag);
            assert(ContentDataIndex >= 0);
            if(RequestData.RawDataLen - ContentDataIndex >= RequestData.ContentLength)
            {
                RequestData.pContentData = RequestData.pRawData + ContentDataIndex;
                return HERROR_SUCCESS;
            }
        }
    }
    return HERROR_SUCCESS;
}

BOOL CWebServerThread::ParseWeekDay(const TCHAR *pToken, WORD &nWeekDay)
{
    BOOL bSuccess = TRUE;
    if(strcmpi(pToken, "Sun") == 0 || strcmpi(pToken, "Sunday") == 0)
        nWeekDay = 0;
    else if(strcmpi(pToken, "Mon") == 0 || strcmpi(pToken, "Monday") == 0)
        nWeekDay = 1;
    else if(strcmpi(pToken, "Tue") == 0 || strcmpi(pToken, "Tuesday") == 0)
        nWeekDay = 2;
    else if(strcmpi(pToken, "Wed") == 0 || strcmpi(pToken, "Wednesday") == 0)
        nWeekDay = 3;
    else if(strcmpi(pToken, "Thu") == 0 || strcmpi(pToken, "Thursday") == 0)
        nWeekDay = 4;
    else if(strcmpi(pToken, "Fri") == 0 || strcmpi(pToken, "Friday") == 0)
        nWeekDay = 5;
    else if(strcmpi(pToken, "Sat") == 0 || strcmpi(pToken, "Saturday") == 0)
        nWeekDay = 6;
    else
        bSuccess = FALSE;
    return bSuccess;
}

BOOL CWebServerThread::ParseMonth(const TCHAR *pToken, WORD &nMonth)
{
    BOOL bSuccess = TRUE;
    if(strcmpi(pToken, "Jan") == 0)
        nMonth = 1;
    else if(strcmpi(pToken, "Feb") == 0)
        nMonth = 2;
    else if(strcmpi(pToken, "Mar") == 0)
        nMonth = 3;
    else if(strcmpi(pToken, "Apr") == 0)
        nMonth = 4;
    else if(strcmpi(pToken, "May") == 0)
        nMonth = 5;
    else if(strcmpi(pToken, "Jun") == 0)
        nMonth = 6;
    else if(strcmpi(pToken, "Jul") == 0)
        nMonth = 7;
    else if(strcmpi(pToken, "Aug") == 0)
        nMonth = 8;
    else if(strcmpi(pToken, "Sep") == 0)
        nMonth = 9;
    else if(strcmpi(pToken, "Oct") == 0)
        nMonth = 10;
    else if(strcmpi(pToken, "Nov") == 0)
        nMonth = 11;
    else if(strcmpi(pToken, "Dec") == 0)
        nMonth = 12;
    else
        bSuccess = FALSE;
    return bSuccess;
}

BOOL CWebServerThread::ParseDateTime(TCHAR *pTimeStr, SYSTEMTIME &Time)
{
    // If-Modified-Since: Sun, 05 Mar 2006 09:27:18 GMT
    if(pTimeStr == NULL)
        return FALSE;

    Time.wMilliseconds = 0;
    if((int)_tcslen(pTimeStr) > 5)
    {
        if(pTimeStr[3] == ',')
        {
            // Week
            const TCHAR *pSteps = _T(", :");
            TCHAR *pToken = _tcstok(pTimeStr, pSteps);
            if(pToken == NULL || !ParseWeekDay(pToken, Time.wDayOfWeek))
                return FALSE;

            // Day
            pToken = _tcstok(NULL, pSteps);
            if(pToken == NULL)
                return FALSE;
            Time.wDay = (WORD)atoi(pToken);

            // Month
            pToken = _tcstok(NULL, pSteps);
            if(pToken == NULL || !ParseMonth(pToken, Time.wMonth))
                return FALSE;

            // Year
            pToken = _tcstok(NULL, pSteps);
            if(pToken == NULL)
                return FALSE;
            Time.wYear = (WORD)atoi(pToken);

            // Hour
            pToken = _tcstok(NULL, pSteps);
            if(pToken == NULL)
                return FALSE;
            Time.wHour = (WORD)atoi(pToken);

            // Minute
            pToken = _tcstok(NULL, pSteps);
            if(pToken == NULL)
                return FALSE;
            Time.wMinute = (WORD)atoi(pToken);

            // Second
            pToken = _tcstok(NULL, pSteps);
            if(pToken == NULL)
                return FALSE;
            Time.wSecond = (WORD)atoi(pToken);
        }
    }

    return TRUE;
}

/*
IE:
GET /images/maintop.jpg HTTP/1.1
Accept: * /*
Referer: http://wbj:81/frame.dll?Lib=netoa&Func=Login
Accept-Language: zh-cn
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; MyIE2; Maxthon; .NET CLR 1.0.3705)
Host: wbj:81
Connection: Keep-Alive
Cookie: tc_total_cookie_datetime_36916=2005-12-23%209%3A32%3A21; txtMainTab=Timeline; Cookie=true; user=Administrator; userid=1; encodepwd=5fa285e1bebe0a6623e33afc04a1fbd5; AppUrlFunc=61

Opera:
GET /frame.dll?Lib=WebPrint&funcid=100 HTTP/1.1
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; zh-cn) Opera 8.50
Host: wbj
Accept: text/html, application/xml;q=0.9, application/xhtml+xml, image/png, image/jpeg, image/gif, image/x-xbitmap, * /*;q=0.1
Accept-Language: zh-cn, en
Accept-Charset: gbk, utf-8, utf-16, iso-8859-1;q=0.6, *;q=0.1
Accept-Encoding: deflate, gzip, x-gzip, identity, *;q=0
Referer: http://wbj/frame.dll?Lib=WebPrint&Func=Login
Cookie: username=Guest; password=202cb962ac59075b964b07152d234b70
Cookie2: $Version=1
Cache-Control: no-cache
Connection: Keep-Alive, TE
TE: deflate, gzip, chunked, identity, trailers
*/
HTTP_ERROR CWebServerThread::ParseRequest(CRequestData &RequestData)
{
    TCHAR *pLineToken = (char *)RequestData.pRawData;
    TCHAR *pEndFlag = _tcsstr(pLineToken, _T("\r\n"));
    if(pEndFlag != NULL)
        *pEndFlag = 0;

    {
        // GET/POST
        TCHAR *pToken = _tcstok(pLineToken, _T(" "));
        if(pToken == NULL)
            return HERROR_BADREQUEST;
        if(_tcsicmp(pToken, _T("GET")) == 0)
            RequestData.RequestMethod = _T("GET");
        else if(_tcsicmp(pToken, _T("POST")) == 0)
            RequestData.RequestMethod = _T("POST");
        else if(_tcsicmp(pToken, _T("HEAD")) == 0)
            RequestData.RequestMethod = _T("HEAD");
        else
            return HERROR_BADREQUEST;

        // FileName and param
        pToken = _tcstok(NULL, _T(" "));
        if(pToken == NULL)
            return HERROR_BADREQUEST;
        TCHAR *pQuestion = _tcschr(pToken, _T('?'));
        if(pQuestion != NULL)
        {
            *pQuestion = 0;
            RequestData.WebFileName = pToken;
            RequestData.QueryString = pQuestion + 1;
            *pQuestion = _T('?');
        }
        else
        {
            RequestData.WebFileName = pToken;
        }

        // Check "HTTP/"
        pToken = _tcstok(NULL, _T(" "));
        if(pToken == NULL || _tcsncmp(pToken, "HTTP/", 5) != 0)
            return HERROR_BADREQUEST;
    }

    while(pEndFlag != NULL)
    {
        pLineToken = pEndFlag + 2;
        pEndFlag = _tcsstr(pLineToken, _T("\r\n"));
        if(pEndFlag != NULL)
            *pEndFlag = 0;

        if(_tcsnicmp(pLineToken, "Cookie:", 7) == 0)
        {
            pLineToken += 7;
            SkipChars(pLineToken, " \t");
            RequestData.CookieString = pLineToken;
        }
        else if(_tcsnicmp(pLineToken, "Content-Type:", 13) == 0)
        {
            pLineToken += 13;
            SkipChars(pLineToken, " \t");
            RequestData.ContentType = pLineToken;
        }
        else if(_tcsnicmp(pLineToken, "soapaction:", 11) == 0)
        {
            pLineToken += 11;
            SkipChars(pLineToken, " \t");
            RequestData.SoapAction = pLineToken;
        }
        else if(_tcsnicmp(pLineToken, "Host:", 5) == 0)
        {
            pLineToken += 5;
            SkipChars(pLineToken, " \t");
            RequestData.HostName = pLineToken;
        }
        else if(_tcsnicmp(pLineToken, "User-Agent:", 11) == 0)
        {
            pLineToken += 11;
            SkipChars(pLineToken, " \t");
            RequestData.UserAgent = pLineToken;
        }
        else if(_tcsnicmp(pLineToken, "Referer:", 8) == 0)
        {
            pLineToken += 8;
            SkipChars(pLineToken, " \t");
            RequestData.Referer = pLineToken;
        }
        else if(_tcsnicmp(pLineToken, "Connection:", 11) == 0)
        {
            pLineToken += 11;
            SkipChars(pLineToken, " \t");
            if(_tcsnicmp(pLineToken, "Keep-Alive", 10) == 0)
                RequestData.bKeepAlive = TRUE;
        }
        else if(_tcsnicmp(pLineToken, "If-Modified-Since:", 18) == 0)
        {
            pLineToken += 18;
            SkipChars(pLineToken, " \t");
            if(ParseDateTime(pLineToken, RequestData.IfModifiedSince))
                RequestData.bIfModifiedSinceValid = TRUE;
        }
        else if(_tcsnicmp(pLineToken, "Range:", 6) == 0)
        {
            pLineToken += 6;
            SkipChars(pLineToken, " \t");
            if(ParseRange(pLineToken, RequestData.RangeBegin, RequestData.RangeEnd))
                RequestData.bRangeValid = TRUE;
        }
        else if(_tcsnicmp(pLineToken, "Authorization:", 14) == 0)
        {
            pLineToken += 14;
            SkipChars(pLineToken, " \t");
            RequestData.Authorization = pLineToken;
        }
        
    }

    LOG_INFO(GID_DECODEURL, "Decode before: %s", (LPCTSTR)RequestData.WebFileName);
    UrlDecode(RequestData.WebFileName);
    LOG_INFO(GID_DECODEURL, "Decode after : %s\r\n", (LPCTSTR)RequestData.WebFileName);

    if(RequestData.WebFileName.IsEmpty())
        RequestData.WebFileName = _T("/");

    if(RequestData.WebFileName[0] != '/')
        return HERROR_BADREQUEST;

    if(RequestData.WebFileName.Find("..") >= 0 || RequestData.WebFileName.Find(':') >= 0)
        return HERROR_FORBIDDEN;

    RequestData.WebFileName.Replace("\\", "/");
    return HERROR_SUCCESS;
}

BOOL CWebServerThread::ParseRange(TCHAR *pRangeStr, __int64 &RangeBegin, __int64 &RangeEnd)
{
  //Range: bytes=11448672-
/*
   Examples of byte-ranges-specifier values (assuming an entity-body of
   length 10000):
     o  The first 500 bytes (byte offsets 0-499, inclusive):
          bytes=0-499

     o  The second 500 bytes (byte offsets 500-999, inclusive):
          bytes=500-999

     o  The final 500 bytes (byte offsets 9500-9999, inclusive):
          bytes=-500
     o  Or
          bytes=9500-

     o  The first and last bytes only (bytes 0 and 9999):
          bytes=0-0,-1
*/
    if(_tcsnicmp(pRangeStr, "bytes", 5) != 0)
        return FALSE;
    pRangeStr += 5;
    SkipChars(pRangeStr, " =");

    TCHAR *pFind = _tcschr(pRangeStr, '-');
    if(pFind == NULL)
        return FALSE;

    *pFind = 0;
    if(pFind == pRangeStr)
        RangeBegin = -1;
    else
        RangeBegin = _ttoi64(pRangeStr);

    pFind++;
    SkipChars(pFind, " ");
    if(*pFind == 0)
        RangeEnd = -1;
    else
        RangeEnd = _ttoi64(pFind);

    if(RangeBegin < 0 && RangeEnd < 0)
        return FALSE;
    if(RangeEnd >= 0 && RangeBegin > RangeEnd)
        return FALSE;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////

BOOL RemoveHandleInheritAttr(HANDLE &hHandle)
{
#if 0
    return SetHandleInformation(hHandle, HANDLE_FLAG_INHERIT, 0);
#else
    HANDLE hTempHanle;
    BOOL bRet = DuplicateHandle(GetCurrentProcess(), hHandle, GetCurrentProcess(), 
        &hTempHanle, 0, FALSE, DUPLICATE_SAME_ACCESS);
    if(!bRet)
    {
        assert(false);
        return FALSE;
    }
    CloseHandle(hHandle);
    hHandle = hTempHanle;
    return TRUE;
#endif
}

typedef void (*PipeIoFUNC)(HANDLE hPipe, LPARAM FuncParam);

BOOL ExecuteShellProcess(const char *pCommandLine, const void *pCgiEnv, const char *pCurDir,
                         PipeIoFUNC pWritePipeFunc, PipeIoFUNC pReadPipeFunc, LPARAM FuncParam)
{
/*
�ܵ�ͼ��
          |----------|
W1----->R1|  �ӽ���  |W2----->R2
          |----------|
*/
    SECURITY_ATTRIBUTES Sa;
    HANDLE hRead1, hWrite1, hRead2, hWrite2;

    Sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    Sa.lpSecurityDescriptor = NULL;
    Sa.bInheritHandle = TRUE;
    if(!CreatePipe(&hRead1, &hWrite1, &Sa, 0)) 
        return FALSE;

    if(!CreatePipe(&hRead2, &hWrite2, &Sa, 0)) 
    {
        CloseHandle(hRead1);
        CloseHandle(hWrite1);
        return FALSE;
    } 

    // ȥ�����hWrite1��hRead2�ļ̳�����
    RemoveHandleInheritAttr(hWrite1); 
    RemoveHandleInheritAttr(hRead2);

    // �����ӽ���
    STARTUPINFO Si;
    PROCESS_INFORMATION Pi; 
    Si.cb = sizeof(STARTUPINFO);
    GetStartupInfo(&Si); 
    Si.hStdInput = hRead1;
    Si.hStdOutput = hWrite2;
    Si.hStdError = hWrite2;
    Si.wShowWindow = SW_HIDE;
    Si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES | STARTF_FORCEOFFFEEDBACK;

    if(!CreateProcess(NULL, (char *)pCommandLine,
        NULL,NULL,TRUE, CREATE_NEW_CONSOLE, (void *)pCgiEnv, pCurDir, &Si, &Pi)) 
    {
        CloseHandle(hWrite1);
        CloseHandle(hRead1);
        CloseHandle(hWrite2);
        CloseHandle(hRead2);
        return FALSE;
    }

    CloseHandle(hRead1);
    CloseHandle(hWrite2);

    // д�ܵ�
    pWritePipeFunc(hWrite1, FuncParam);
    CloseHandle(hWrite1);

    // ���ܵ�
    pReadPipeFunc(hRead2, FuncParam);
    CloseHandle(hRead2);

    // �ȴ��ӽ��̽���
    WaitForSingleObject(Pi.hProcess, INFINITE);
    CloseHandle(Pi.hProcess);
    CloseHandle(Pi.hThread);
    return TRUE;
}

static void WritePipeFunc(HANDLE hPipe, LPARAM FuncParam)
{
    CWebServerThread *pServerThread = (CWebServerThread *)FuncParam;
    assert(pServerThread != NULL);

    const CRequestData &RequestData = pServerThread->RequestData;
    if(RequestData.ContentLength > 0)
    {
        DWORD BytesWrite = 0;
        BOOL bRet = WriteFile(hPipe, RequestData.pContentData, RequestData.ContentLength, &BytesWrite, NULL);
        assert(bRet);
        assert(RequestData.ContentLength == BytesWrite);
    }
}

static void GetLocationContent(MtSTRING &Content, const char *pLocation)
{
    Content.Format("<head><title>Document Moved</title></head>"
        "<body><h1>Object Moved</h1>This document may be found <a HREF=\"%s\">here</a></body>",
        pLocation);
}

static void ReadPipeFunc(HANDLE hPipe, LPARAM FuncParam)
{
    CWebServerThread *pServerThread = (CWebServerThread *)FuncParam;
    assert(pServerThread != NULL);

    char Buffer[4096];
    DWORD BytesRead = 0, CurRead = 0; 
    BOOL bHeaderSent = FALSE;
    while(1) 
    {
        BOOL bReadRet = ReadFile(hPipe, Buffer + BytesRead, 4095 - BytesRead, &CurRead, NULL) && CurRead > 0;
        if(bReadRet)
            BytesRead += CurRead;

        if(!bHeaderSent)
        {
            Buffer[BytesRead] = 0;
            pServerThread->bResponseKeepAlive = FALSE;

            int HeaderSepLen = 4;
            char *pHeaderEnd = strstr(Buffer, "\r\n\r\n");
            if(pHeaderEnd == NULL)
            {
                pHeaderEnd = strstr(Buffer, "\n\n");
                HeaderSepLen = 2;
            }
            if(pHeaderEnd == NULL)
            {
                if(BytesRead < 4000 && bReadRet)
                    continue;

                MtSTRING BodyStr;
                BodyStr.Format("<h1>CGI Error</h1> The header is:<pre>%s</pre>", Buffer);
                pServerThread->SendHttpErrorStr("502 Gateway Error", BodyStr);
                return;
            }
            *pHeaderEnd = 0;
            bHeaderSent = TRUE;

            StrLIST AdditionalHeaderLines;
            MtSTRING Status, Location;
            char *pLineToken = strtok(Buffer, "\r\n");
            while(pLineToken != NULL)
            {
                if(strnicmp(pLineToken, "Status:", 7) == 0)
                {
                    pLineToken += 7;
                    SkipChars(pLineToken, " \t");
                    Status = pLineToken;
                }
                else if(strnicmp(pLineToken, "Location:", 9) == 0)
                {
                    pLineToken += 9;
                    SkipChars(pLineToken, " \t");
                    Location = pLineToken;
                    Status = "302 Object Moved";
                }
                else
                {
                    AdditionalHeaderLines.AddTail(pLineToken);
                }

                pLineToken = strtok(NULL, "\r\n");
            }
            if(Status.IsEmpty())
                Status = "200 OK";
            CResponseHeader Header;
            Header.AddStatus(Status);
            Header.AddServer(pServerThread->GetWebServer()->GetServerConfig().ServerName);
            Header.AddConnection(0);
            if(!Location.IsEmpty())
            {
                Header.AddContentType("text/html");
                Header.AddLocation(Location);
                Header.ResponseHeader += _T("\r\n");
            }
            else
            {
                MtSTRING ExtraHeader;
                AdditionalHeaderLines.AddTail("\r\n");
                AdditionalHeaderLines.FromListToString(ExtraHeader);
                Header.AddExtraHeaders(ExtraHeader);
            }

            LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)Header.ResponseHeader);
            pServerThread->GetSocket().SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());

            if(!Location.IsEmpty())
            {
                MtSTRING Content;
                GetLocationContent(Content, Location);
                pServerThread->GetSocket().SendAll((const BYTE *)(LPCTSTR)Content, Content.GetLength());
            }
            else
            {
                pServerThread->GetSocket().SendAll((BYTE *)(pHeaderEnd + HeaderSepLen), 
                    BytesRead - (pHeaderEnd - Buffer + HeaderSepLen));
            }

            if(!bReadRet)
                return;
        }
        else
        {
            if(!bReadRet)
                return;
            pServerThread->GetSocket().SendAll((BYTE *)Buffer, BytesRead);
        }
        BytesRead = 0;
    } 
}

BOOL CWebServerThread::ExecuteCgiProcess(const CRequestData &RequestData)
{
    MemFILE2 CgiEnv;
    BuildCgiEnvironment(RequestData, CgiEnv);

    MtSTRING ScriptFileName(((CWebServer *)pServer)->ServerConfig.RootDirectory);
    if(ScriptFileName.Right(1) == "\\")
        ScriptFileName.Delete(ScriptFileName.GetLength() - 1, 1);
    ScriptFileName += RequestData.ScriptName;
    ScriptFileName.Replace("/", "\\");

    MtSTRING CurrentDir(ScriptFileName);
    char *pFileName = strrchr(CurrentDir.GetBuffer(CurrentDir.GetLength()), '\\');
    assert(pFileName != NULL);
    *pFileName = 0;
    CurrentDir.ReleaseBuffer();

    MtSTRING CommandLine(RequestData.LocalFileName);
    CommandLine.Replace("%s", (LPCTSTR)ScriptFileName);

    return ExecuteShellProcess(CommandLine, CgiEnv.GetPtr(), (LPCTSTR)CurrentDir, WritePipeFunc, 
        ReadPipeFunc, (LPARAM)this);
}

#define SET_CGI_ENVI(Title, Str) \
  { \
    const char *pTitle = Title; \
    MemFile.Write(pTitle, (int)strlen(pTitle)); \
    MemFile.Write((LPCTSTR)(Str), (Str).GetLength() + 1); \
  } \

// �ϳ� CGI ��������Ļ�������
// �˺����д����Ч�ʺͰ�ȫ��
void CWebServerThread::BuildCgiEnvironment(const CRequestData &RequestData, MemFILE2 &MemFile)
{
    for(TCHAR **pVariable = _tenviron; *pVariable; pVariable++ )
    {
        if((*pVariable)[0] != '_')
            MemFile.Write(*pVariable, lstrlen(*pVariable) + 1);
    }

    TCHAR TempStr[2048]; // ע�����------------

    // SERVER_SOFTWARE
    const char *pServerSoftware = "SERVER_SOFTWARE=" WEBSERVER_NAME_VERSION;
    MemFile.Write(pServerSoftware, lstrlen(pServerSoftware) + 1);

    // SERVER_PROTOCOL
    const char *pServerProtocol = "SERVER_PROTOCOL=HTTP/1.1";
    MemFile.Write(pServerProtocol, lstrlen(pServerProtocol) + 1);

    // SERVER_PORT
    int Len = wsprintf(TempStr, "SERVER_PORT=%d", ((CWebServer *)pServer)->ServerConfig.ListenPort);
    MemFile.Write(TempStr, Len + 1);

    // SERVER_NAME
    char HostName[256];
    if(gethostname(HostName, 256) != 0)
        HostName[0] = 0;
    Len = wsprintf(TempStr, "SERVER_NAME=%s", HostName);
    MemFile.Write(TempStr, Len + 1);

    // REMOTE_ADDR
    Len = wsprintf(TempStr, "REMOTE_ADDR=%s", inet_ntoa(GetClientAddr().sin_addr));
    MemFile.Write(TempStr, Len + 1);

    // GATEWAY_INTERFACE
    const char *pGategayIfc = "GATEWAY_INTERFACE=CGI/1.1";
    MemFile.Write(pGategayIfc, lstrlen(pGategayIfc) + 1);

    // DOCUMENT_ROOT
    SET_CGI_ENVI("DOCUMENT_ROOT=", ((CWebServer *)pServer)->ServerConfig.RootDirectory);

    // SCRIPT_NAME
    SET_CGI_ENVI("SCRIPT_NAME=", RequestData.ScriptName);

    // REQUEST_METHOD
    SET_CGI_ENVI("REQUEST_METHOD=", RequestData.RequestMethod);

    // QUERY_STRING
    if(!RequestData.QueryString.IsEmpty())
    {
        SET_CGI_ENVI("QUERY_STRING=", RequestData.QueryString);
    }

    // CONTENT_LENGTH
    Len = wsprintf(TempStr, "CONTENT_LENGTH=%d", RequestData.ContentLength);
    MemFile.Write(TempStr, Len + 1);

    // CONTENT_TYPE
    if(!RequestData.ContentType.IsEmpty())
    {
        SET_CGI_ENVI("CONTENT_TYPE=", RequestData.ContentType);
    }

    // HTTP_COOKIE
    if(!RequestData.CookieString.IsEmpty())
    {
        SET_CGI_ENVI("HTTP_COOKIE=", RequestData.CookieString);
    }

    // HTTP_USER_AGENT
    SET_CGI_ENVI("HTTP_USER_AGENT=", RequestData.UserAgent);

    // HTTP_HOST
    SET_CGI_ENVI("HTTP_HOST=", RequestData.HostName);

    // PATH_INFO
    if(!RequestData.PathInfo.IsEmpty())
    {
        SET_CGI_ENVI("PATH_INFO=", RequestData.PathInfo);
    }

    // PATH_TRANSLATED
    MtSTRING PathTrans(((CWebServer *)pServer)->ServerConfig.RootDirectory);
    if(PathTrans.Right(1) == "\\")
        PathTrans.Delete(PathTrans.GetLength() - 1, 1);
    PathTrans += RequestData.PathInfo;
    PathTrans.Replace("/", "\\");
    SET_CGI_ENVI("PATH_TRANSLATED=", PathTrans);

    // REDIRECT_STATUS
    const char *pRedirectStatus = "REDIRECT_STATUS=200";
    MemFile.Write(pRedirectStatus, lstrlen(pRedirectStatus) + 1);

    // HTTP_REFERER
    if(!RequestData.Referer.IsEmpty())
    {
        SET_CGI_ENVI("HTTP_REFERER=", RequestData.Referer);
    }

    // HTTP_AUTHORIZATION
    if(!RequestData.Authorization.IsEmpty())
    {
        SET_CGI_ENVI("HTTP_AUTHORIZATION=", RequestData.Authorization);
    }
    // End
    MemFile.Write("", 1);
}

//////////////////////////////////////////////////////////////////////////

BOOL WINAPI ReadClient(HCONN ConnID, LPVOID lpvBuffer, LPDWORD lpdwSize)
{
    CWebServerThread *pServerThread = (CWebServerThread *)ConnID;
    if(pServerThread == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    assert(false);
    SetLastError(ERROR_NO_DATA);
    return FALSE;
}

BOOL WINAPI WriteClient(HCONN ConnID, LPVOID Buffer, LPDWORD lpdwBytes, DWORD dwSync)
{
    CWebServerThread *pServerThread = (CWebServerThread *)ConnID;
    if(pServerThread == NULL || lpdwBytes == NULL || dwSync == HSE_IO_ASYNC)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    LOG_INFO(GID_WEBSERVER, "WriteClient 1, Len=%d", *lpdwBytes);
    BOOL bRet = pServerThread->GetSocket().SendAll((const BYTE *)Buffer, (int)*lpdwBytes) == (int)(*lpdwBytes);
    LOG_INFO(GID_WEBSERVER, "WriteClient 2");
    return bRet;
}

#define GET_SERVER_VARIABLE_COPYSTR(pStr, Len) \
    if(*pBufferSize >= (DWORD)(Len)) \
    { \
      strcpy((char *)pBuffer, (pStr)); \
      *pBufferSize = (Len); \
      return TRUE; \
    } \
    else \
    { \
      SetLastError(ERROR_INSUFFICIENT_BUFFER); \
      return FALSE; \
    } \


BOOL WINAPI GetServerVariable(HCONN ConnID, char *pVariableName, void *pBuffer,
                              DWORD *pBufferSize)
{
    CWebServerThread *pServerThread = (CWebServerThread *)ConnID;
    if(pServerThread == NULL)
        return FALSE;

    if(pBufferSize == NULL)
        return FALSE;

    if(stricmp(pVariableName, "HTTP_COOKIE") == 0)
    {
        const MtSTRING &CookieString = pServerThread->RequestData.CookieString;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)CookieString, CookieString.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "CONTENT_TYPE") == 0)
    {
        const MtSTRING &ContentType = pServerThread->RequestData.ContentType;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)ContentType, ContentType.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "REMOTE_ADDR") == 0)
    {
        const char *pRemoteAddr = inet_ntoa(pServerThread->GetClientAddr().sin_addr);
        GET_SERVER_VARIABLE_COPYSTR(pRemoteAddr, (DWORD)strlen(pRemoteAddr) + 1);
    }
    else if(stricmp(pVariableName, "REMOTE_HOST") == 0) 
    {  // �д�֤ʵ
        const char *pRemoteAddr = inet_ntoa(pServerThread->GetClientAddr().sin_addr);
        GET_SERVER_VARIABLE_COPYSTR(pRemoteAddr, (DWORD)strlen(pRemoteAddr) + 1);
    }
    else if(stricmp(pVariableName, "HTTP_SOAPACTION") == 0)
    {
        const MtSTRING &SoapAction = pServerThread->RequestData.SoapAction;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)SoapAction, SoapAction.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "SERVER_PORT") == 0)
    {
        char TempStr[64];
        int Len = 1 + sprintf(TempStr, "%d", pServerThread->GetWebServer()->GetServerConfig().ListenPort);
        GET_SERVER_VARIABLE_COPYSTR(TempStr, Len);
    }
    else if(stricmp(pVariableName, "SERVER_PROTOCOL") == 0)
    {
        const char *pServerProtocol = "HTTP/1.1";
        int Len = (int)strlen(pServerProtocol) + 1;
        GET_SERVER_VARIABLE_COPYSTR(pServerProtocol, Len);
    }
    else if(stricmp(pVariableName, "SERVER_SOFTWARE") == 0)
    {
        const MtSTRING &ServerName = pServerThread->GetWebServer()->GetServerConfig().ServerName;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)ServerName, ServerName.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "QUERY_STRING") == 0)
    {
        const MtSTRING &QueryString = pServerThread->RequestData.QueryString;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)QueryString, QueryString.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "PATH_INFO") == 0)
    {
        const MtSTRING &PathInfo = pServerThread->RequestData.PathInfo;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)PathInfo, PathInfo.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "SCRIPT_NAME") == 0)
    {
        const MtSTRING &ScriptName = pServerThread->RequestData.ScriptName;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)ScriptName, ScriptName.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "REQUEST_METHOD") == 0)
    {
        const MtSTRING &RequestMethod = pServerThread->RequestData.RequestMethod;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)RequestMethod, RequestMethod.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "SERVER_NAME") == 0)
    {
        char HostName[256];
        if(gethostname(HostName, 256) != 0)
            HostName[0] = 0;

        GET_SERVER_VARIABLE_COPYSTR(HostName, (DWORD)strlen(HostName) + 1);
    }
    else if(stricmp(pVariableName, "CONTENT_LENGTH") == 0)
    {
        char TempStr[64];
        int Len = 1 + sprintf(TempStr, "%d", pServerThread->RequestData.ContentLength);

        GET_SERVER_VARIABLE_COPYSTR(TempStr, Len);
    }
    else if(stricmp(pVariableName, "PATH_TRANSLATED") == 0)
    {
        MtSTRING PathTrans(pServerThread->GetWebServer()->GetServerConfig().RootDirectory);
        if(PathTrans.Right(1) == "\\")
            PathTrans.Delete(PathTrans.GetLength() - 1, 1);
        PathTrans += pServerThread->RequestData.PathInfo;
        PathTrans.Replace("/", "\\");
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)PathTrans, PathTrans.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "HTTPS") == 0)
    {
        const char *pHttps = "off";
        int Len = (int)strlen(pHttps) + 1;
        GET_SERVER_VARIABLE_COPYSTR(pHttps, Len);
    }
    else if(stricmp(pVariableName, "URL") == 0)
    {
        const MtSTRING &Url = pServerThread->RequestData.WebFileName;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)Url, Url.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "ALL_HTTP") == 0)
    {
        MtSTRING TempStr, ResultStr;
        ResultStr.Format("HTTP_HOST:%s\n", (LPCTSTR)pServerThread->RequestData.HostName);

        // UserAgent
        TempStr.Format("HTTP_USER_AGENT:%s\n", (LPCTSTR)pServerThread->RequestData.UserAgent);
        ResultStr += TempStr;

        // Referer
        MtSTRING &Referer = pServerThread->RequestData.Referer;
        if(!Referer.IsEmpty())
        {
            TempStr.Format("HTTP_REFERER:%s\n", (LPCTSTR)Referer);
            ResultStr += TempStr;
        }

        // Authorization
        MtSTRING &Authorization = pServerThread->RequestData.Authorization;
        if(!Authorization.IsEmpty())
        {
            TempStr.Format("HTTP_AUTHORIZATION:%s\n", (LPCTSTR)Authorization);
            ResultStr += TempStr;
        }

        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)ResultStr, ResultStr.GetLength() + 1);
    }

    else if(stricmp(pVariableName, "HTTP_AUTHORIZATION") == 0)
    {
        MtSTRING &Authorization = pServerThread->RequestData.Authorization;
        if(!Authorization.IsEmpty())
        {
            GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)Authorization, Authorization.GetLength() + 1);
        }
        else
        {
            SetLastError(ERROR_NO_DATA);
            return FALSE;
        }
    }
    else if(stricmp(pVariableName, "HTTP_USER_AGENT") == 0)
    {
        const MtSTRING &UserAgent = pServerThread->RequestData.UserAgent;
        GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)UserAgent, UserAgent.GetLength() + 1);
    }
    else if(stricmp(pVariableName, "HTTP_REFERER") == 0)
    {
        MtSTRING &Referer = pServerThread->RequestData.Referer;
        if(!Referer.IsEmpty())
        {
            GET_SERVER_VARIABLE_COPYSTR((LPCTSTR)Referer, Referer.GetLength() + 1);
        }
        else
        {
            SetLastError(ERROR_NO_DATA);
            return FALSE;
        }
    }

#if 0 && defined _DEBUG
    OutputDebugString(pVariableName);
#endif
    //assert(false);
    SetLastError(ERROR_INVALID_INDEX);
    return FALSE;
}

#ifndef   HSE_REQ_CLOSE_CONNECTION
#define   HSE_REQ_CLOSE_CONNECTION                 (HSE_REQ_END_RESERVED+17)
#endif

BOOL WINAPI ServerSupportFunction(HCONN ConnID, DWORD HSERRequest, void *pBuffer,
                                  DWORD *pSize, DWORD *pDataType)
{
    CWebServerThread *pServerThread = (CWebServerThread *)ConnID;
    if(pServerThread == NULL)
        return FALSE;

    switch(HSERRequest)
    {
        case HSE_REQ_CLOSE_CONNECTION:
        {
            // do nothing
            return TRUE;
        }
        case HSE_REQ_IS_KEEP_CONN:
        {
            *((BOOL *)pBuffer) = pServerThread->bResponseKeepAlive;
            return TRUE;
        }
        case HSE_REQ_SEND_URL:
        case HSE_REQ_SEND_URL_REDIRECT_RESP:
        {
            const char *pUrl = (const char *)pBuffer;

            CResponseHeader Header;
            Header.AddStatus("302 Object Moved");
            Header.AddLocation(pUrl);
            Header.AddServer(pServerThread->GetWebServer()->GetServerConfig().ServerName);
            Header.AddContentType(_T("text/html"));
            Header.AddConnection(pServerThread->bResponseKeepAlive);
            Header.AddContentLength(0);
            Header.ResponseHeader += "\r\n";

            pServerThread->GetSocket().SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());
            return TRUE;
        }
        case HSE_REQ_SEND_RESPONSE_HEADER:
        {
            const char *pStatusString = (const char *)pBuffer;
            const char *pExtraHeaders = (const char *)pDataType;

            CResponseHeader Header;
            if(pStatusString && pStatusString[0])
                Header.AddStatus(pStatusString);
            else
                Header.AddStatus("200 OK");

            Header.AddServer(pServerThread->GetWebServer()->GetServerConfig().ServerName);
            pServerThread->bResponseKeepAlive = FALSE;
            Header.AddConnection(FALSE); 
            // IIS5.1�������Ƿ���pExtraHeaders����û��Content-Length�У�
            //   ����У�����bResponseKeepAlive��ԭ��ֵ
            //   ���û�У�����ConnectionΪclose

            if(pExtraHeaders && *pExtraHeaders)
                Header.AddExtraHeaders(pExtraHeaders);

            pServerThread->GetSocket().SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());
            LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)(Header.ResponseHeader));
            return TRUE;
        }
        case HSE_REQ_SEND_RESPONSE_HEADER_EX:
        {
            CResponseHeader Header;
            HSE_SEND_HEADER_EX_INFO *pHeader = (HSE_SEND_HEADER_EX_INFO *)pBuffer;
            if(pHeader->pszStatus && pHeader->pszStatus[0])
                Header.AddStatus(pHeader->pszStatus);
            else
                Header.AddStatus("200 OK");

            Header.AddServer(pServerThread->GetWebServer()->GetServerConfig().ServerName);

            pServerThread->bResponseKeepAlive = pHeader->fKeepConn;
            Header.AddConnection(pServerThread->bResponseKeepAlive);

            if(pHeader->pszHeader && pHeader->pszHeader[0])
                Header.ResponseHeader += pHeader->pszHeader;

            pServerThread->GetSocket().SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());
            LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)(Header.ResponseHeader));
            return TRUE;
        }
        case HSE_REQ_MAP_URL_TO_PATH:
        {
            char *pURL = (char *)pBuffer;
            MtSTRING PhysicalUrl(pServerThread->GetWebServer()->GetServerConfig().RootDirectory);
            PhysicalUrl += pURL;
            PhysicalUrl.Replace("/", "\\");

            assert(pSize != NULL);
            if(*pSize >= (DWORD)(PhysicalUrl.GetLength() + 1))
            {
                strcpy(pURL, PhysicalUrl);
                return TRUE;
            }
            else
            {
                *pSize = PhysicalUrl.GetLength() + 1;
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return FALSE; 
            }
        }
        case HSE_REQ_MAP_URL_TO_PATH_EX:
        {
            const char *pURL = (const char *)pBuffer;
            HSE_URL_MAPEX_INFO *pUMI = (HSE_URL_MAPEX_INFO *)pDataType;

            const MtSTRING &RootDir = pServerThread->GetWebServer()->GetServerConfig().RootDirectory;

            // Flags
            pUMI->dwFlags = (HSE_URL_FLAGS_READ | HSE_URL_FLAGS_EXECUTE | HSE_URL_FLAGS_SCRIPT);
            pUMI->cchMatchingPath = RootDir.GetLength();
            pUMI->cchMatchingURL = 0; // ������Ŀ¼�й� -----��ȷ��

            // Url
            MtSTRING PhysicalUrl(RootDir);
            PhysicalUrl += pURL;
            PhysicalUrl.Replace("/", "\\");
            strncpy(pUMI->lpszPath, (LPCTSTR)PhysicalUrl, MAX_PATH - 1);
            pUMI->lpszPath[MAX_PATH - 1] = 0;
            if(PhysicalUrl.GetLength() < MAX_PATH - 1)
                return TRUE;
            else
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return FALSE;
            }
            return TRUE;
        }
        case HSE_REQ_GET_IMPERSONATION_TOKEN:
        {
            break;
        }
        case HSE_REQ_DONE_WITH_SESSION:
        {
            pServerThread->GetSocket().Close();
            if(!pServerThread->Wait(1000))
            {
                assert(false);
                pServerThread->Terminate();
            }
            delete pServerThread;
            return TRUE;
        }
        default:
        {
            assert(false);
        }
    }
    SetLastError(ERROR_INVALID_INDEX);
    return FALSE;
}

void CWebServer::AddOneCacheDll(const CCacheDllData &CacheDllData)
{
    CritSectOwner Guard(CacheDllListCs);

    CacheDllList.AddTail(CacheDllData);
}

const CCacheDllData *CWebServer::FindCacheDll(const TCHAR *pDllFileName)
{
    CritSectOwner Guard(CacheDllListCs);

    CacheDllListPOS FindPos = CacheDllList.GetHeadPosition();
    for(; FindPos != NULL; FindPos = FindPos->GetNext())
    {
        if(FindPos->Data.DllFileName.CompareNoCase(pDllFileName) == 0)
            return &(FindPos->Data);
    }
    return NULL;
}

HTTP_ERROR CWebServerThread::ExecuteIsapiDll(const CRequestData &RequestData)
{
    assert(GetWebServer()->ServerConfig.bEnableIsapi);

    const CCacheDllData *pCacheDll = NULL;
    if(GetWebServer()->ServerConfig.bIsapiCache)
    {
        pCacheDll = GetWebServer()->FindCacheDll(RequestData.LocalFileName);
    }

    CCacheDllData CacheDllData;
    if(pCacheDll == NULL) 
    { 
        // LoadLibrary
        //CacheDllData.hDll = ::LoadLibrary(RequestData.LocalFileName);
        CacheDllData.hDll = ::LoadLibraryEx(RequestData.LocalFileName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
        if(CacheDllData.hDll == NULL)
        {
            DWORD Err = GetLastError();
            return HERROR_BADISAPI;
        }

        // GetProcAddress
        CacheDllData.pGetExtensionVersion = (GetExtensionVersionFUNC)GetProcAddress(CacheDllData.hDll, _T("GetExtensionVersion"));
        CacheDllData.pHttpExtensionProc = (HttpExtensionProcFUNC)GetProcAddress(CacheDllData.hDll, _T("HttpExtensionProc"));
        CacheDllData.pTerminateExtension = (TerminateExtensionFUNC)GetProcAddress(CacheDllData.hDll, _T("TerminateExtension"));
        if(CacheDllData.pGetExtensionVersion == NULL || CacheDllData.pHttpExtensionProc == NULL)
        {
            ::FreeLibrary(CacheDllData.hDll);
            return HERROR_BADISAPI;
        }

        // GetExtensionVersion
        try
        {
            HSE_VERSION_INFO HseVer;
            CacheDllData.pGetExtensionVersion(&HseVer);
        }
        catch(...)
        {
            assert(false);
        }

        pCacheDll = &CacheDllData;
        if(GetWebServer()->ServerConfig.bIsapiCache)
        {
            CacheDllData.DllFileName = RequestData.LocalFileName;
            GetWebServer()->AddOneCacheDll(CacheDllData);
        }
    }
    assert(pCacheDll != NULL);

    if(pECB == NULL)
        pECB = new EXTENSION_CONTROL_BLOCK;
    pECB->cbSize            = sizeof(EXTENSION_CONTROL_BLOCK);
    pECB->dwVersion         = MAKELONG(HSE_VERSION_MINOR, HSE_VERSION_MAJOR);
    pECB->ConnID            = (HCONN)this;
    pECB->dwHttpStatusCode  = 200;
    pECB->lpszLogData[0]    = 0;
    pECB->lpszMethod        = (LPSTR)(LPCTSTR)RequestData.RequestMethod;
    pECB->lpszQueryString   = (LPSTR)(LPCTSTR)RequestData.QueryString;
    pECB->lpszPathInfo      = (LPSTR)(LPCTSTR)RequestData.PathInfo;
    pECB->lpszPathTranslated= (LPSTR)(LPCTSTR)RequestData.LocalFileName;//---------
    pECB->cbTotalBytes      = RequestData.ContentLength;
    pECB->cbAvailable       = RequestData.ContentLength; 
    pECB->lpbData           = RequestData.pContentData;
    pECB->lpszContentType   = (LPSTR)(LPCTSTR)RequestData.ContentType;
    pECB->GetServerVariable = GetServerVariable;
    pECB->WriteClient       = WriteClient;
    pECB->ReadClient        = ReadClient;
    pECB->ServerSupportFunction = ServerSupportFunction;

    HTTP_ERROR Ret = HERROR_SUCCESS;
    try
    {
        /*
        const char *pContinue = "HTTP/1.1 100 Continue\r\n"
        "Server: Microsoft-IIS/5.1\r\n";
        CResponseHeader Header;
        Header.ResponseHeader = pContinue;
        Header.AddCurrentTime();
        Header.ResponseHeader += "\r\n";
        TheSocket.SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());
        */
        DWORD Result = pCacheDll->pHttpExtensionProc(pECB);

        if(Result == HSE_STATUS_SUCCESS || Result == HSE_STATUS_SUCCESS_AND_KEEP_CONN)
        {
        }
        else if(Result == HSE_STATUS_PENDING)
        {
            bDeleteThis = FALSE;
            //hEventDoneSession = CreateEvent(NULL, TRUE, FALSE, NULL);
            //WaitForSingleObject(hEventDoneSession, INFINITE);
            //CloseHandle(hEventDoneSession);
            //Sleep(2000);
        }
        else
        {
            Ret = HERROR_EXCEPTION;
            this->bResponseKeepAlive = FALSE;
        }
    }
    catch(...)
    {
        assert(false);
        Ret = HERROR_EXCEPTION;
        this->bResponseKeepAlive = FALSE;
    }

    if(!(GetWebServer()->ServerConfig.bIsapiCache))
    {
        try
        {
            if(pCacheDll->pTerminateExtension != NULL)
                pCacheDll->pTerminateExtension(HSE_TERM_MUST_UNLOAD);
        }
        catch(...)
        {
            assert(false);
        }
        ::FreeLibrary(pCacheDll->hDll);
    }
    return Ret;
}

//////////////////////////////////////////////////////////////////////////

const TCHAR *CWebServerThread::GetFileContentType(const TCHAR *pFileExtName)
{
    static struct 
    {
        const TCHAR *pFileExtName;
        const TCHAR *pContentType;
    } FileContentType[] = 
    {
        _T("htm"),    _T("text/html"),
        _T("html"),   _T("text/html"),
        _T("txt"),    _T("text/plain"),
        _T("gif"),    _T("image/gif"),
        _T("jpg"),    _T("image/jpeg"),
        _T("css"),    _T("text/css"),
        _T("js"),     _T("application/x-javascript"),
        _T("doc"),    _T("application/msword"),
        _T("xls"),    _T("application/vnd.ms-excel"),
        _T("zip"),    _T("application/x-zip-compressed"),
    };

    if(pFileExtName != NULL)
    {
        for(int i = 0; i < ARRAY_SIZE(FileContentType); i++)
        {
            if(_tcsicmp(pFileExtName, FileContentType[i].pFileExtName) == 0)
                return FileContentType[i].pContentType;
        }
    }

    return _T("application/octet-stream");
}

BOOL CWebServerThread::SendHttpErrorStr(const TCHAR *pResponseCmd, const TCHAR *pResponseText)
{
    MtSTRING HtmlStr;
    HtmlStr.Format("<html><head><title>Error</title></head><body>%s</body></html>", pResponseText);

    CResponseHeader Header;
    Header.AddStatus(pResponseCmd);
    Header.AddServer(((CWebServer *)pServer)->ServerConfig.ServerName);
    Header.AddConnection(FALSE);
    bResponseKeepAlive = FALSE;
    Header.AddContentLength(HtmlStr.GetLength());
    Header.AddContentType("text/html");
    Header.ResponseHeader += _T("\r\n");

    TheSocket.SendAll((const BYTE *)(LPCTSTR)(Header.ResponseHeader), Header.ResponseHeader.GetLength());
    LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)(Header.ResponseHeader));

    return TheSocket.SendAll((const BYTE *)(LPCTSTR)HtmlStr, HtmlStr.GetLength()) == HtmlStr.GetLength();
}

BOOL CWebServerThread::SendHttpFile()
{
    HANDLE hFile = ::CreateFile(RequestData.LocalFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if(hFile == INVALID_HANDLE_VALUE)
    {
        assert(false);
        SendHttpErrorStr("404 Object Not Found", "Object Not Found");
        return FALSE;
    }

    BOOL bRet = FALSE;

    FILETIME FileTimeLastModify, FileTimeRequest;
    ::GetFileTime(hFile, NULL, NULL, &FileTimeLastModify);

    if(RequestData.RequestMethod == "GET" && 
        RequestData.bIfModifiedSinceValid &&
        ::SystemTimeToFileTime(&RequestData.IfModifiedSince, &FileTimeRequest) &&
        ::CompareFileTime(&FileTimeLastModify, &FileTimeRequest) == 0)
    {
        // �ļ�û�б��޸�
        CResponseHeader Header;
        Header.AddStatus("304 Not Modified");
        Header.AddServer(((CWebServer *)pServer)->ServerConfig.ServerName);
        Header.AddConnection(this->bResponseKeepAlive);
        Header.AddContentLength(0);
        Header.ResponseHeader += _T("\r\n");
        bRet = TheSocket.SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength()) == Header.ResponseHeader.GetLength();
        LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)Header.ResponseHeader);
    }
    else
    {
        const char *pFileExtName = strrchr(RequestData.LocalFileName, '.');
        if(pFileExtName != NULL)
            pFileExtName++;
        const char *pContentType = GetFileContentType(pFileExtName);
        assert(pContentType != NULL);

        unsigned __int64 FileLength = 0;
        DWORD FileLengthLow = GetFileSize(hFile, (DWORD *)&FileLength);
        FileLength <<= 32;
        FileLength |= FileLengthLow;

        SYSTEMTIME SysTimeLastModify;
        ::FileTimeToSystemTime(&FileTimeLastModify, &SysTimeLastModify);

        if(RequestData.bRangeValid)
        {
            if(RequestData.RangeBegin == -1)
            {
                assert(RequestData.RangeEnd >= 0);
                RequestData.RangeBegin = FileLength - (unsigned __int64)RequestData.RangeEnd;
                if(RequestData.RangeBegin < 0)
                    RequestData.RangeBegin = 0;
                RequestData.RangeEnd = FileLength - 1;
            }
            else if(RequestData.RangeEnd == -1)
            {
                RequestData.RangeEnd = FileLength - 1;
            }
            else
            {
                if((unsigned __int64)RequestData.RangeEnd >= FileLength)
                    RequestData.RangeEnd = FileLength - 1;
            }

            __int64 SendTotalLen = RequestData.RangeEnd - RequestData.RangeBegin + 1;
            if(SendTotalLen <= 0 || (unsigned __int64)RequestData.RangeBegin >= FileLength)
            {
                CResponseHeader Header;
                Header.AddStatus("416 Requested Range Not Satisfiable");
                Header.AddServer(((CWebServer *)pServer)->ServerConfig.ServerName);
                Header.AddConnection(this->bResponseKeepAlive);
                Header.AddContentRange(FileLength);
                Header.AddContentLength(0);
                Header.ResponseHeader += _T("\r\n");
                TheSocket.SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());
                LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)Header.ResponseHeader);
                CloseHandle(hFile);
                return FALSE;
            }
            assert(RequestData.RangeBegin >= 0 && (unsigned __int64)RequestData.RangeBegin < FileLength);
            assert(RequestData.RangeEnd >= 0 && (unsigned __int64)RequestData.RangeEnd < FileLength);
            assert(RequestData.RangeBegin <= RequestData.RangeEnd);

            CResponseHeader Header;
            Header.AddStatus("206 Partial content");
            Header.AddServer(((CWebServer *)pServer)->ServerConfig.ServerName);
            Header.AddContentType(pContentType);
            Header.AddLastModified(SysTimeLastModify);
            Header.AddConnection(this->bResponseKeepAlive);
            Header.AddContentLength(SendTotalLen);
            Header.AddContentRange(RequestData.RangeBegin, RequestData.RangeEnd, FileLength);
            Header.ResponseHeader += _T("\r\n");
            TheSocket.SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());
            LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)Header.ResponseHeader);

            if(RequestData.RequestMethod == "HEAD")
            {
                bRet = TRUE;
            }
            else
            {
                ::SetFilePointer(hFile, (LONG)RequestData.RangeBegin, (LONG *)&RequestData.RangeBegin + 1, FILE_BEGIN);

                BYTE Buffer[4096];
                DWORD ReadSize = 0;
                while(SendTotalLen > 0)
                {
                    ReadSize = SendTotalLen > 4096 ? 4096 : (DWORD)SendTotalLen;
                    bRet = ::ReadFile(hFile, Buffer, ReadSize, &ReadSize, NULL);
                    if(!bRet || ReadSize <= 0 || TheSocket.SendAll((const BYTE *)Buffer, ReadSize) != (int)ReadSize)
                    {
                        //bRet = FALSE;
                        //bRet = TRUE;
                        break;
                    }

                    SendTotalLen -= ReadSize;
                }
            }
        }
        else
        {
            CResponseHeader Header;
            Header.AddStatus("200 OK");
            Header.AddServer(((CWebServer *)pServer)->ServerConfig.ServerName);
            Header.AddContentType(pContentType);
            Header.AddLastModified(SysTimeLastModify);
            Header.AddConnection(this->bResponseKeepAlive);
            Header.AddContentLength(FileLength);
            Header.ResponseHeader += _T("\r\n");
            TheSocket.SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());

            LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)Header.ResponseHeader);

            if(RequestData.RequestMethod == "HEAD")
            {
                bRet = TRUE;
            }
            else
            {
                BYTE Buffer[4096];
                DWORD ReadSize = 0;
                while(FileLength > 0)
                {
                    ReadSize = FileLength > 4096 ? 4096 : (DWORD)FileLength;
                    bRet = ::ReadFile(hFile, Buffer, ReadSize, &ReadSize, NULL);
                    if(!bRet || ReadSize <= 0 || TheSocket.SendAll((const BYTE *)Buffer, ReadSize) != (int)ReadSize)
                    {
                        //bRet = FALSE;
                        //bRet = TRUE;
                        break;
                    }

                    FileLength -= ReadSize;
                }
            }
        }
    }

    CloseHandle(hFile);
    return bRet;
}

template <class ARG_TYPE>
class TPtrLIST : public TLIST<ARG_TYPE *>
{
public:
    ~TPtrLIST()
    {
        POSITION Pos = this->GetHeadPosition();
        for(; Pos != NULL; Pos = Pos->GetNext())
            delete Pos->Data;
    }
};

typedef WIN32_FIND_DATA * FIND_DATA_PTR;
typedef TPtrLIST<WIN32_FIND_DATA> FileDataLIST;

static void GetFileDataList(const TCHAR *pDirName, FileDataLIST &FileDataList)
{
    assert(pDirName && *pDirName);

    MtSTRING DirName = pDirName;
    if(DirName[DirName.GetLength() - 1] != _T('\\'))
        DirName += _T('\\');

    WIN32_FIND_DATA *pFileData = new WIN32_FIND_DATA;
    HANDLE hFind = FindFirstFile(DirName + _T("*.*"), pFileData);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            //����ǵ�ǰĿ¼��Ŀ¼, ����
            if(_tcscmp(pFileData->cFileName, _T(".")) == 0 || 
                _tcscmp(pFileData->cFileName, _T("..")) == 0)
                continue;
            FileDataList.AddTail(pFileData);
            pFileData = new WIN32_FIND_DATA;

        } while(FindNextFile(hFind, pFileData));

        FindClose(hFind);
    }
    delete pFileData;
}

static void FuncLinkEncode(MtSTRING &LinkStr)
{
    LinkStr.Replace("%", "%25");
    LinkStr.Replace(" ", "%20");
    LinkStr.Replace("+", "%2B");
}

static int FileDataCompareFunc(const FIND_DATA_PTR &Data1, const FIND_DATA_PTR &Data2)
{
    BOOL bIsDir1 = Data1->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
    BOOL bIsDir2 = Data2->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
    if(bIsDir1 != bIsDir2)
        return bIsDir2 - bIsDir1;
    return _tcsicmp(Data1->cFileName, Data2->cFileName);
}

BOOL CWebServerThread::BrowseDirectory(const TCHAR *pWebDirName, const TCHAR *pLocalDirName)
{
    assert(pWebDirName != NULL);
    assert(pWebDirName[0] == '/');
    assert(IsDirectoryExist(pLocalDirName));

    this->bResponseKeepAlive = FALSE;

    CResponseHeader Header;
    Header.AddStatus("200 OK");
    Header.AddServer(GetWebServer()->GetServerConfig().ServerName);
    Header.AddConnection(0);
    Header.ResponseHeader += "Content-Type: text/html\r\n\r\n";
    TheSocket.SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength());

    MtSTRING ItemText;
    ItemText.Format("<head><title>%s - %s</title></head><body><H1>%s - %s</H1><hr><pre>\r\n", 
        (LPCTSTR)RequestData.HostName, pWebDirName, (LPCTSTR)RequestData.HostName, pWebDirName);
    TheSocket.SendAll((const BYTE *)(LPCTSTR)ItemText, ItemText.GetLength());

    if(_tcscmp(pWebDirName, _T("/")) != 0)
    {
        MtSTRING ParentWebDirName(pWebDirName);
        TCHAR *pBuffer = ParentWebDirName.GetBuffer(ParentWebDirName.GetLength());
        assert(pBuffer[lstrlen(pBuffer) - 1] == '/');
        pBuffer[lstrlen(pBuffer) - 1] = 0;
        TCHAR *pFind = _tcsrchr(pBuffer, '/');
        assert(pFind != NULL);
        pFind[1] = 0;
        ParentWebDirName.ReleaseBuffer();

        FuncLinkEncode(ParentWebDirName);
        ItemText.Format("<A HREF=\"%s\">[To Parent Directory]</A>\r\n\r\n", (LPCTSTR)ParentWebDirName);
        TheSocket.SendAll((const BYTE *)(LPCTSTR)ItemText, ItemText.GetLength());
    }

    // GetFileDataList
    FileDataLIST FileDataList;
    GetFileDataList(pLocalDirName, FileDataList);

    // Sort
    FileDataList.SortQuick(FileDataCompareFunc);

    // Output
    FILETIME LocalTime;
    SYSTEMTIME FileTime;
    TCHAR DateStr[20], TimeStr[20];
    DWORD DirCount = 0, FileCount = 0;
    FileDataLIST::POSITION FilePos = FileDataList.GetHeadPosition();
    for(; FilePos != NULL; FilePos = FilePos->GetNext())
    {
        WIN32_FIND_DATA &FileData = *(FilePos->Data);
        BOOL bIsDir = FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

        ::FileTimeToLocalFileTime(&FileData.ftLastWriteTime, &LocalTime);
        ::FileTimeToSystemTime(&LocalTime, &FileTime);

        GetDateFormat(LOCALE_SYSTEM_DEFAULT, 0, &FileTime, "yyyy��MM��dd��", DateStr, 20);
        GetTimeFormat(LOCALE_SYSTEM_DEFAULT, LOCALE_NOUSEROVERRIDE, &FileTime, NULL, TimeStr, 20);

        MtSTRING LinkStr(pWebDirName);
        LinkStr += FileData.cFileName;
        FuncLinkEncode(LinkStr);

        if(bIsDir)
        { 
            ItemText.Format(_T("%20s %10s %18s  <a href=\"%s/\">%s</a>\r\n"), 
                DateStr, TimeStr,
                "&lt;DIR&gt;", (LPCTSTR)LinkStr, FileData.cFileName);
            DirCount++;
        }
        else
        {
            ItemText.Format(_T("%20s %10s %12I64u  <a href=\"%s\">%s</a>\r\n"), 
                DateStr, TimeStr,
                ((unsigned __int64)FileData.nFileSizeHigh << 32) | FileData.nFileSizeLow, (LPCTSTR)LinkStr, FileData.cFileName);
            FileCount++;
        }

        TheSocket.SendAll((const BYTE *)(LPCTSTR)ItemText, ItemText.GetLength());
    }

    ItemText.Format("<hr>Total: %d dir(s), %d file(s)</pre></body>", DirCount, FileCount);
    TheSocket.SendAll((const BYTE *)(LPCTSTR)ItemText, ItemText.GetLength());
    return TRUE;
}

/*
   ת��������·��
   ȡ���ļ����ԣ���Ŀ¼��
   if(��)
   {
     if(���һ���ַ�����/)
       ���/

     BOOL bDirBrowse = FALSE;
     if(����Ŀ¼���)
     {
       if(����Ŀ¼���)
         bDirBrowse = TRUE;
       else if(!����ȱʡ�ĵ�())
         bDirBrowse = TRUE;
       if(bDirBrowse)
       {
         ��ʾĿ¼�������
         ��־
         return;
       }
     }
     else
     {
       if(!����ȱʡ�ĵ�())
       {
         ����:û���ҵ��ļ�
         ��־
         return;
       }
     }
   }
   ִ�л����ļ�
   ��־
*/

// �������TRUE, LocalFilePath���ش��ڵ��ļ���
// �������FALSE���Ͳ�Ҫ�ı�LocalFilePath
const TCHAR *CWebServerThread::GetExistDefaultHtml(MtSTRING &LocalFilePath, const StrLIST &DefaultDoclList)
{
    // �д����Ч��
    assert(LocalFilePath.Right(1) == "\\");
    StrListPOS ListPos = DefaultDoclList.GetHeadPosition();
    for(; ListPos != NULL; ListPos = ListPos->GetNext())
    {
        if(IsFileExist(LocalFilePath + ListPos->Data))
            return (LPCTSTR)(ListPos->Data);
    }
    return NULL;
}

BOOL ParseEngineCommandLine(const MtSTRING &CommandLine, MtSTRING &EnginePath, MtSTRING &EngineParam)
{
    MtSTRING EngineCommandLine(CommandLine);
    EngineCommandLine.TrimLeft();
    EngineCommandLine.TrimRight();
    if(EngineCommandLine.IsEmpty())
        return FALSE;

    int CommandParamPos = 0;
    if(EngineCommandLine[0] == '\"')
    {
        int FindPos = EngineCommandLine.Find("\"", 1);
        if(FindPos < 0)
            return FALSE;
        assert(FindPos >= 1);
        EnginePath = EngineCommandLine.Mid(1, FindPos - 1);
        if(FindPos < EngineCommandLine.GetLength() - 1)
        {
            if(EngineCommandLine[FindPos + 1] == ' ')
                CommandParamPos = FindPos + 2;
            else
                return FALSE;
        }
    }
    else
    {
        int FindPos = EngineCommandLine.Find(" ");
        if(FindPos < 0)
            EnginePath = EngineCommandLine;
        else
        {
            EnginePath = EngineCommandLine.Left(FindPos);
            CommandParamPos = FindPos + 1;
        }
    }

    if(CommandParamPos > 0)
    {
        EngineParam = EngineCommandLine.Right(EngineCommandLine.GetLength() - CommandParamPos);
        EngineParam.TrimLeft();
    }
    else
    {
        EngineParam.Empty();
    }
    return TRUE;
}

//#define TIME_TEST

#ifdef TIME_TEST
#include "caltime.h"
static CalTIME TTotal, TRead, TParse, TExecSend, TLog;
#endif

/*
·��ת���㷨��
�ȷֽ⣿��ȡ��ǰ��Ĳ���

�Ƿ���ִ��Ȩ�ޣ�
if(��)
{
  ��.exe, dll��
  if(�ҵ�)
  {
    if(�ļ�����)
      ִ�г����ű�
    else
      ��ҳ������
    return;
  }
}

if(��Ŀ¼)
{
  ��ȱʡ�ĵ�
  if(�ҵ�)
    �ݹ�
  else if(����Ŀ¼���)
    Ŀ¼���
  else
    ��ҳ������
}
else if(���ļ�)
  �����ļ�
else
  ��ҳ������
*/

BOOL CWebServerThread::ProcessRequest(CRequestData &RequestData, const MtSTRING &WebFileName, BOOL &bExecute)
{
    CWebServer *pWebServer = (CWebServer *)pServer;

    if(pWebServer->ServerConfig.bEnableScript)
    {
        EngineLIST::POSITION EnginePos = pWebServer->ServerConfig.ScriptEngineList.GetHeadPosition();
        for(; EnginePos != NULL; EnginePos = EnginePos->GetNext())
        {
            const CScriptEngine &Engine = EnginePos->Data;
            int FindPos = WebFileName.FindNoCase(Engine.ExtName);
            if(FindPos > 0 && (((LPCTSTR)WebFileName)[FindPos + Engine.ExtName.GetLength()] == 0 || ((LPCTSTR)WebFileName)[FindPos + Engine.ExtName.GetLength()] == '/'))
            {
                bExecute = TRUE;
                RequestData.ScriptName = WebFileName.Left(FindPos + Engine.ExtName.GetLength());
                RequestData.PathInfo = RequestData.ScriptName;

                MtSTRING EnginePath, EngineParam;
                BOOL bRet = ParseEngineCommandLine(EnginePos->Data.CommandLine, EnginePath, EngineParam);
                assert(bRet);

                if(_tcsicmp((LPCTSTR)EnginePath + EnginePath.GetLength() - 4, ".exe") == 0)
                {
                    RequestData.LocalFileName = EnginePos->Data.CommandLine;
                    if(!ExecuteCgiProcess(RequestData))
                    {
                        MtSTRING ErrStr;
                        ErrStr.Format(_T("Create CGI process failed. [%s]"), (LPCTSTR)RequestData.ScriptName);
                        SendHttpErrorStr("500 Server Error", ErrStr);
                        return FALSE;
                    }
                }
                else
                {
                    RequestData.LocalFileName = EnginePath;
                    HTTP_ERROR Result = ExecuteIsapiDll(RequestData);
                    if(Result != HERROR_SUCCESS)
                    {
                        if(Result == HERROR_BADISAPI)
                        {
                            MtSTRING ErrStr;
                            ErrStr.Format(_T("Execute ISAPI failed. [%s]"), (LPCTSTR)RequestData.WebFileName);
                            SendHttpErrorStr("500 Server Error", ErrStr);
                        }
                        return FALSE;
                    }
                }
                return TRUE;
            }
        }
    }

    if(pWebServer->ServerConfig.bEnableIsapi)
    {
        int FindPos = WebFileName.FindNoCase(".dll");
        if(FindPos > 0 && (((LPCTSTR)WebFileName)[FindPos + 4] == 0 || ((LPCTSTR)WebFileName)[FindPos + 4] == '/'))
        {
            RequestData.ScriptName = WebFileName.Left(FindPos + 4);
            RequestData.PathInfo = (LPCTSTR)WebFileName + FindPos + 4;

            RequestData.LocalFileName = RequestData.ScriptName;
            RequestData.LocalFileName.Replace(_T("/"), _T("\\"));
            RequestData.LocalFileName.Insert(0, pWebServer->ServerConfig.RootDirectory);

            bExecute = TRUE;
            HTTP_ERROR Result = ExecuteIsapiDll(RequestData);
            if(Result != HERROR_SUCCESS)
            {
                if(Result == HERROR_BADISAPI)
                {
                    MtSTRING ErrStr;
                    ErrStr.Format(_T("Execute ISAPI failed. [%s]"), (LPCTSTR)RequestData.WebFileName);
                    SendHttpErrorStr("500 Server Error", ErrStr);
                }
                return FALSE;
            }
            return TRUE;
        }
    }

    if(pWebServer->ServerConfig.bEnableCgi)
    {
        int FindPos = WebFileName.FindNoCase(".exe");
        if(FindPos > 0 && (((LPCTSTR)WebFileName)[FindPos + 4] == 0 || ((LPCTSTR)WebFileName)[FindPos + 4] == '/'))
        {
            RequestData.ScriptName = WebFileName.Left(FindPos + 4);
            RequestData.PathInfo = (LPCTSTR)WebFileName + FindPos + 4;

            RequestData.LocalFileName = RequestData.ScriptName;
            RequestData.LocalFileName.Replace(_T("/"), _T("\\"));
            RequestData.LocalFileName.Insert(0, pWebServer->ServerConfig.RootDirectory);

            bExecute = TRUE;
            if(!ExecuteCgiProcess(RequestData))
            {
                MtSTRING ErrStr;
                ErrStr.Format(_T("Create CGI process failed. [%s]"), (LPCTSTR)RequestData.ScriptName);
                SendHttpErrorStr("500 Server Error", ErrStr);
                return FALSE;
            }
            return TRUE;
        }

        FindPos = WebFileName.FindNoCase(".cgi");
        if(FindPos > 0 && (((LPCTSTR)WebFileName)[FindPos + 4] == 0 || ((LPCTSTR)WebFileName)[FindPos + 4] == '/'))
        {
            RequestData.ScriptName = WebFileName.Left(FindPos + 4);
            RequestData.PathInfo = (LPCTSTR)WebFileName + FindPos + 4;

            RequestData.LocalFileName = RequestData.ScriptName;
            RequestData.LocalFileName.Replace(_T("/"), _T("\\"));
            RequestData.LocalFileName.Insert(0, pWebServer->ServerConfig.RootDirectory);

            bExecute = TRUE;
            if(!ExecuteCgiProcess(RequestData))
            {
                MtSTRING ErrStr;
                ErrStr.Format(_T("Create CGI process failed. [%s]"), (LPCTSTR)RequestData.ScriptName);
                SendHttpErrorStr("500 Server Error", ErrStr);
                return FALSE;
            }
            return TRUE;
        }
    }

    RequestData.LocalFileName = WebFileName;
    RequestData.LocalFileName.Replace(_T("/"), _T("\\"));
    RequestData.LocalFileName.Insert(0, pWebServer->ServerConfig.RootDirectory);

    DWORD Attr = GetFileAttributes(RequestData.LocalFileName);
    if(Attr == INVALID_FILE_ATTRIBUTES)
    {
        // ��ҳ������
        SendHttpErrorStr("404 Object Not Found", "Object Not Found");
        return FALSE;
    }

    if(Attr & FILE_ATTRIBUTE_DIRECTORY)
    {
        if(RequestData.LocalFileName.Right(1) != "\\")
        {
            CResponseHeader Header;
            Header.AddStatus("302 Object Moved");
            MtSTRING TempStr;
            TempStr.Format("Location: http://%s%s/\r\n", (LPCTSTR)RequestData.HostName, (LPCTSTR)RequestData.WebFileName);
            Header.ResponseHeader += TempStr;
            Header.AddServer(((CWebServer *)pServer)->ServerConfig.ServerName);
            Header.AddConnection(this->bResponseKeepAlive);
            Header.AddContentLength(0);
            Header.ResponseHeader += _T("\r\n");

            LOG_INFO(GID_WEBSERVER, "Send HttpHeader:\r\n%s", (LPCTSTR)Header.ResponseHeader);
            return TheSocket.SendAll((const BYTE *)(LPCTSTR)Header.ResponseHeader, Header.ResponseHeader.GetLength()) == Header.ResponseHeader.GetLength();
        }

        const TCHAR *pDefaultDoc = NULL;
        if(pWebServer->ServerConfig.bEnableShowDir)
        {
            if(pWebServer->ServerConfig.bShowDirAlways)
            {
                return BrowseDirectory(RequestData.WebFileName, RequestData.LocalFileName);
            }
            pDefaultDoc = GetExistDefaultHtml(RequestData.LocalFileName, pWebServer->ServerConfig.DefaultDoclList);
            if(pDefaultDoc == NULL)
            {
                return BrowseDirectory(RequestData.WebFileName, RequestData.LocalFileName);
            }
        }
        else
        {
            pDefaultDoc = GetExistDefaultHtml(RequestData.LocalFileName, pWebServer->ServerConfig.DefaultDoclList);
            if(pDefaultDoc == NULL)
            {
                SendHttpErrorStr("404 Object Not Found", "Object Not Found");
                return FALSE;
            }
        }
        assert(pDefaultDoc != NULL);

        MtSTRING NewWebFileName(WebFileName);
        assert(NewWebFileName.Right(1) == "/");
        NewWebFileName += pDefaultDoc;
        return ProcessRequest(RequestData, NewWebFileName, bExecute);
    }
    else
    {
        return SendHttpFile(); // RequestData.LocalFileName
    }
}

int CWebServerThread::ServerProc()
{
    LOG_INFO(GID_WEBSERVER, "CWebServerThread::ServerProc");

#ifdef TIME_TEST
    TTotal.BeginCountTime();
#endif
    CWebServer *pWebServer = (CWebServer *)pServer;

    TheSocket.SetSendTimeout(pWebServer->ServerConfig.NetTimeout);
    TheSocket.SetRecvTimeout(pWebServer->ServerConfig.NetTimeout);

    do
    {
#ifdef TIME_TEST
        TRead.BeginCountTime();
#endif
        bResponseKeepAlive = FALSE;

        LOG_INFO(GID_WEBSERVER, "---ReadRequest Begin.");
        HTTP_ERROR Ret = ReadRequest(RequestData, pWebServer->ServerConfig.NetTimeout, 1024);
        if(Ret != HERROR_SUCCESS)
        {
            if(Ret == HERROR_NETWORK)
            {
                // do nothing
            }
            else if(Ret == HERROR_CONTENTLENGTH || Ret == HERROR_HEADERLENGTH)
            {
                SendHttpErrorStr("400 Bad Request", "Length is incorrect.");
                pWebServer->OnRequestLog(ClientAddr, RequestData, FALSE, FALSE);
            }
            else
            {
                assert(false);
            }
            
            LOG_INFO(GID_WEBSERVER, "ReadRequest error, Ret=%d [����]", Ret);
            return 0;
        }

#ifdef TIME_TEST
        TRead.EndCountTime();
#endif

#if 0 && defined _DEBUG
        FILE *pFile = fopen("d:\\http.txt", "ab");
        if(pFile != NULL)
        {
            fwrite(RequestData.pRawData, 1, RequestData.RawDataLen, pFile);
            fwrite("\r\n\r\n", 1, 4, pFile);
            fclose(pFile);
        }
#endif

#ifdef TIME_TEST
        TParse.BeginCountTime();
#endif
        LOG_INFO(GID_WEBSERVER, "ReadRequest End, Data:\r\n%s", RequestData.pRawData);

        Ret = ParseRequest(RequestData);
        if(Ret != HERROR_SUCCESS)
        {
            if(Ret == HERROR_BADREQUEST)
                SendHttpErrorStr("400 Bad Request", "The parameter is incorrect.");
            else if(Ret == HERROR_FORBIDDEN)
                SendHttpErrorStr("403 Forbidden", "403 Forbidden");
            else
                assert(false);
            pWebServer->OnRequestLog(ClientAddr, RequestData, FALSE, FALSE);
            LOG_INFO(GID_WEBSERVER, "ParseRequest error, Ret=%d [����]", Ret);
            return 0;
        }
        RequestData.bValidate = TRUE;
        bResponseKeepAlive = RequestData.bKeepAlive;
        LOG_INFO(GID_WEBSERVER, "ParseRequest End, bKeepAlive=%d", RequestData.bKeepAlive);

#ifdef TIME_TEST
        TParse.EndCountTime();
        TExecSend.BeginCountTime();
#endif
        BOOL bExecute = FALSE;
        BOOL bSuccess = ProcessRequest(RequestData, RequestData.WebFileName, bExecute);

#ifdef TIME_TEST
        TExecSend.EndCountTime();
        TLog.BeginCountTime();
#endif

        pWebServer->OnRequestLog(ClientAddr, RequestData, bExecute, bSuccess);
        LOG_INFO(GID_WEBSERVER, "ProcessRequest End, bExecute=%d, bSuccess=%d, bResponseKeepAlive=%d", 
            bExecute, bSuccess, bResponseKeepAlive);

        if(bResponseKeepAlive)
            RequestData.SetEmpty();

    } while(bResponseKeepAlive);

#ifdef TIME_TEST
    TLog.EndCountTime();
    TTotal.EndCountTime();
#endif

     return 0;
}
/*
GET / HTTP/1.1
Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-powerpoint, application/vnd.ms-excel, application/msword, * /*
Accept-Language: zh-cn
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; MyIE2; Maxthon; .NET CLR 1.0.3705)
Host: www.google.com
Connection: Keep-Alive
Cookie: PREF=ID=817c4b78fac07bb9:NW=1:TM=1133438437:LM=1135060552:IG=2:S=323sLWy3Y-upQRQl; rememberme=false


HTTP/1.1 302 Found
Location: http://www.google.com/intl/zh-CN/
Set-Cookie: PREF=ID=817c4b78fac07bb9:NW=1:TM=1133438437:LM=1135074112:IG=2:S=0XI2_DuGIyT_eIUl; expires=Sun, 17-Jan-2038 19:14:07 GMT; path=/; domain=.google.com
Content-Type: text/html
Server: GWS/2.1
Transfer-Encoding: chunked
Content-Encoding: gzip
Date: Tue, 20 Dec 2005 10:21:52 GMT
Cache-Control: private, x-gzip-ok=""


GET /aa.htm HTTP/1.1
Accept: * /*
Accept-Language: zh-cn
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; MyIE2; Maxthon; .NET CLR 1.0.3705)
Host: wbj:81
Connection: Keep-Alive
*/

CWebServerConfig::CWebServerConfig()
{
    ListenPort    = 80;
    MaxThreadNum  = 100;
    bEnableCgi    = TRUE;
    bEnableIsapi  = TRUE;
    bIsapiCache   = TRUE;
    bEnableScript = TRUE;
    bEnableShowDir= FALSE;
    bShowDirAlways= FALSE;
    NetTimeout    = 5000;
    bAutoRun      = FALSE;
    bIconStartStop= FALSE;
    bLogToWindow  = TRUE;
    LogWndMaxLine = 5000;
    bLogToFile    = FALSE;
    ServerName    = WEBSERVER_NAME_VERSION;
    MaxContentLength = 16 * 1024 * 1024;
    MaxHeaderLength  = 4096;
}

void CWebServerConfig::SetDefaultHtmlList(const TCHAR *pDefaultHtmlStr)
{
    DefaultDoclList.FromStringToList(pDefaultHtmlStr, " \t,;");
}

void CWebServerConfig::GetDefaultHtmlStr(MtSTRING &DefaultHtmlStr) const
{
    DefaultDoclList.FromListToString(DefaultHtmlStr, ",");
}

CWebServer::CWebServer()
{
}

CWebServer::~CWebServer()
{
}

BOOL CWebServer::Init(const CWebServerConfig &Config)
{
    if(Config.RootDirectory.IsEmpty())
    {
        LastErrStr = _T("��Ŀ¼����Ϊ��!");
        return FALSE;
    }

    if(!IsDirectoryExist(Config.RootDirectory))
    {
        LastErrStr.Format(_T("��Ŀ¼[%s]������!"), (LPCTSTR)Config.RootDirectory);
        return FALSE;
    }

    if(Config.NetTimeout <= 0)
    {
        LastErrStr = _T("��ʱʱ��������0");
        return FALSE;
    }

    assert(Config.MaxThreadNum >= 0);

    ServerConfig = Config;
    ServerConfig.RootDirectory.TrimRight("\\/");

    if(!CNetServer::Init(ServerConfig.ListenPort, ServerConfig.MaxThreadNum))
        return FALSE;

    return TRUE;
}

void CWebServer::OnServerStarted()
{
    assert(CacheDllList.IsEmpty());
}

void CWebServer::OnServerClosed()
{
    if(ServerConfig.bEnableIsapi && ServerConfig.bIsapiCache)
    {
        CritSectOwner Guard(CacheDllListCs);

        CacheDllListPOS ListPos = CacheDllList.GetHeadPosition();
        for(; ListPos != NULL; ListPos = ListPos->GetNext())
        {
            try
            {
                if(ListPos->Data.pTerminateExtension != NULL)
                    ListPos->Data.pTerminateExtension(HSE_TERM_MUST_UNLOAD);
            }
            catch(...)
            {
                // do nothing
                assert(false);
            }
            ::FreeLibrary(ListPos->Data.hDll);
        }
        CacheDllList.RemoveAll();
    }
    else
    {
        assert(CacheDllList.IsEmpty());
    }

#ifdef TIME_TEST
    MtSTRING TimeText;
    TimeText += TTotal.GetTotalTimeStr("Total");
    TimeText += "\r\n";
    TimeText += TRead.GetTotalTimeStr("Read");
    TimeText += "\r\n";
    TimeText += TParse.GetTotalTimeStr("Parse");
    TimeText += "\r\n";
    TimeText += TExecSend.GetTotalTimeStr("ExecSend");
    TimeText += "\r\n";
    TimeText += TLog.GetTotalTimeStr("Log");

    MessageBox(0, TimeText, "ʱ�����", 0);

    TTotal.ReSetZeroTime();
    TRead.ReSetZeroTime();
    TParse.ReSetZeroTime();
    TExecSend.ReSetZeroTime();
    TLog.ReSetZeroTime();

    //TTotal.PopMessage(0, "Total");
#endif
}

void CWebServer::OnServerTimestep()
{
}

void CWebServer::OnRequestLog(const SOCKADDR_IN &ClientAddr, const CRequestData &RequestData, 
                             BOOL bExecute, BOOL bSuccess)
{
}
