#include "stdafx.h"
#include "resource.h"
#include "mtstring.h"
#include "aboutdlg.h"

#define ID_TIMER_SCROLL         100
#define WM_STARTSCROLL          WM_USER + 100
#define WM_STOPSCROLL           WM_USER + 101

#pragma warning(disable:4311)
#pragma warning(disable:4312)

using namespace minilib;

// ������ɫ���亯��
COLORREF GetGradualColor(COLORREF Color1, COLORREF Color2, int TotalLen, int CurPos)
{
    assert(CurPos >= 0 && CurPos <= TotalLen);
    int R =  GetRValue(Color1) + (GetRValue(Color2) - GetRValue(Color1)) * CurPos / TotalLen;
    int G =  GetGValue(Color1) + (GetGValue(Color2) - GetGValue(Color1)) * CurPos / TotalLen;
    int B =  GetBValue(Color1) + (GetBValue(Color2) - GetBValue(Color1)) * CurPos / TotalLen;
    return RGB(R, G, B);
}

// ��һ�ַ������Ƶ�������
static bool CopyToClipboard(const char *pText)
{
    assert(pText != NULL);

    HANDLE hClipboard = GlobalAlloc(GHND | GMEM_SHARE, lstrlen(pText) + 1);
    if(!hClipboard)
        return false;
    char *pBuffer = (char *)GlobalLock(hClipboard);
    lstrcpy(pBuffer, pText);
    GlobalUnlock(hClipboard);

    if(!OpenClipboard(NULL)) // maybe this paramer is hWnd
        return false;
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hClipboard);
    CloseClipboard();
    return true;
}

LRESULT APIENTRY StaticSubclassProc(HWND hWnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
    static HDC hMemDc, hMemDc2;
    static HBITMAP hMemBmp, hMemBmp2;
    static LOGFONT LogFont;
    static int PosY, Height;
    static RECT ClientRect;
    static char *pText[] =
    {
        "��EasyWebServer��վ��������V1.92",
        "",
        "����һ��С�͵�Web����������������Ժܿ��ٵ�����",
        "��PC�ϴ���һ��վ�㣬������IIS���Ӵ��ӵĹ��ߡ�",
        "������Ҫ�����ص����£�",
        "",
        "�� ��ѭHTTP/1.1Э���׼",
        "�� ֧��CGI/ISAPI��֧��PHP/ASP/Perl�ű�",
        "�� ֧���Զ���˿ڡ���������������糬ʱ",
        "�� ֧���Զ���ȱʡ�ĵ��б�֧��Ŀ¼���",
        "�� ֧������UTF-8����",
        "�� ֧��Cookie��֧��SOAP��",
        "�� ֧�ֶ��߳��ļ����ء��ϵ�����",
        "�� ֧�ַ�����־��¼",
        "�� ���ٵ���Դռ�ã�����ķ����ٶȣ����򵥵�����",
        "�� ��ɫ��������밲װ����дע���",
        "�� VC++ SDK ��д�������С",
        "",
        "��ӭ���ԣ�",//����������ı�������ͽ���",
        "����Bug���������� baojianjob@tom.com",
        "Copyright (C) 2007.11 ������"
    };

    /*
    ���Ǹĳ���WM_ERASEBKGND�л����䱳��
    ����memdc�������õ���ˢ�µķ���
    */
    switch(Message)
    {
        case WM_STARTSCROLL:
        {
            ::GetClientRect(hWnd, &ClientRect);

            if(hMemDc != NULL)
                return 0;
            HDC hDc = ::GetDC(hWnd);
            hMemDc = CreateCompatibleDC(hDc);
            hMemBmp = CreateCompatibleBitmap(hDc, ClientRect.right, ClientRect.bottom);
            SelectObject(hMemDc, hMemBmp);
            for(int i = 0; i < ClientRect.bottom; i++)
            {
                MoveToEx(hMemDc, 0, i, NULL);
                COLORREF Color1 = ::GetSysColor(COLOR_BTNFACE);
                //COLORREF Color1 = RGB(0, 0, 0);
                COLORREF Color2 = RGB(255, 255, 255);
                //COLORREF Color2 = ::GetSysColor(COLOR_BTNFACE);

                bool bUp = i < ClientRect.bottom / 2;
                COLORREF Color = GetGradualColor(bUp ? Color1 : Color2, bUp ? Color2 : Color1, ClientRect.bottom, i);

                HPEN hPen = ::CreatePen(PS_SOLID, 1, Color);
                HPEN hPenOld = (HPEN)::SelectObject(hMemDc, hPen);
                LineTo(hMemDc, ClientRect.right, i);
                ::DeleteObject(::SelectObject(hMemDc, hPenOld));
            }

            hMemDc2 = CreateCompatibleDC(hDc);
            hMemBmp2 = CreateCompatibleBitmap(hDc, ClientRect.right, ClientRect.bottom);
            SelectObject(hMemDc2, hMemBmp2);
            ::ReleaseDC(hWnd, hDc);

            ::memset(&LogFont, 0, sizeof(LOGFONT));
            lstrcpy(LogFont.lfFaceName, "����");
            LogFont.lfWeight = 400;
            LogFont.lfHeight = -12;
            LogFont.lfCharSet = 134;
            LogFont.lfOutPrecision = 3;
            LogFont.lfClipPrecision = 2;
            LogFont.lfQuality = 1;
            LogFont.lfPitchAndFamily = 2;

            Height = sizeof(pText) / sizeof(pText[0]) * 16;
            PosY = -Height;

            ::SetTimer(hWnd, ID_TIMER_SCROLL, (UINT)WParam, NULL);
            return 0;
        }
        case WM_STOPSCROLL:
        {
            if(hMemDc != NULL)
            {
                ::KillTimer(hWnd, ID_TIMER_SCROLL);
                ::DeleteDC(hMemDc);
                ::DeleteDC(hMemDc2);
                DeleteObject(hMemBmp);
                DeleteObject(hMemBmp2);
                hMemDc = hMemDc2 = NULL;
                hMemBmp = hMemBmp2 = NULL;
            }
            return 0;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT Ps;
            HDC hDc = ::BeginPaint(hWnd, &Ps);

            RECT ClientRect;
            ::GetClientRect(hWnd, &ClientRect);

            assert(hMemDc != NULL);
            ::BitBlt(hMemDc2, 0, 0, ClientRect.right, ClientRect.bottom, hMemDc, 0, 0, SRCCOPY);
            ::SetBkMode(hMemDc2, TRANSPARENT);
            ::SetTextColor(hMemDc2, RGB(0, 0, 255));
            HFONT hFont = ::CreateFontIndirect(&LogFont);
            HFONT hFontOld = (HFONT)::SelectObject(hMemDc2, hFont);

            for(int i = 0; i < sizeof(pText) / sizeof(pText[0]); i++)
            {
                int CurPosY = PosY + i * 16;
                if(CurPosY >= -16 && CurPosY <= ClientRect.bottom)
                    TextOut(hMemDc2, 5, CurPosY, pText[i], lstrlen(pText[i]));
            }
            ::DeleteObject(::SelectObject(hMemDc2, hFontOld));

            ::BitBlt(hDc, 0, 0, ClientRect.right, ClientRect.bottom, hMemDc2, 0, 0, SRCCOPY);

            ::EndPaint(hWnd, &Ps);
            return 0;
        }
        case WM_TIMER:
        {
            POINT CursorPos;
            ::GetCursorPos(&CursorPos);
            ::ScreenToClient(hWnd, &CursorPos);
            if(::PtInRect(&ClientRect, CursorPos))
                return 0;

            PosY--;
            if(PosY < -Height)
                PosY = ClientRect.bottom;

            ::InvalidateRect(hWnd, NULL, FALSE);

            return 0;
        }
        case WM_CONTEXTMENU:
        {
            POINT Pt;
            ::GetCursorPos(&Pt);

            POINT PtTemp = Pt;
            ::ScreenToClient(hWnd, &PtTemp);
            if(!::PtInRect(&ClientRect, PtTemp))
                return 0;

            HMENU hMenu = ::CreateMenu();
            HMENU hMenuPop = ::CreateMenu();
            ::AppendMenu(hMenuPop, MF_STRING, 100, "����(&C)");
            ::AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hMenuPop, "");

            TrackPopupMenu(hMenuPop, TPM_LEFTALIGN | TPM_RIGHTBUTTON, Pt.x, Pt.y, 0, hWnd, NULL);

            ::DestroyMenu(hMenuPop);
            ::DestroyMenu(hMenu);

            return 0;
        }
        case WM_COMMAND:
        {
            if(WParam == 100) // ����˵�����ݵ��ڴ�
            {
                MtSTRING Text;
                for(int i = 0; i < sizeof(pText) / sizeof(pText[0]); i++)
                {
                    Text += pText[i];
                    Text += "\r\n";
                }
                CopyToClipboard(Text);
            }
            return 0;
        }
    }

    WNDPROC pDefStaticProc = (WNDPROC)::GetWindowLong(hWnd, GWL_USERDATA);
    return CallWindowProc(pDefStaticProc, hWnd, Message, WParam, LParam);
}

BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT Message, WPARAM WParam, LPARAM LParam)
{
    static HWND hWndAuthor;
    switch(Message)
    {
        case WM_INITDIALOG:
        {
            hWndAuthor = GetDlgItem(hDlg, IDC_STATIC_ABOUT);
            LONG DefStaticProc = SetWindowLong(hWndAuthor, GWL_WNDPROC, (LONG)StaticSubclassProc);
            SetWindowLong(hWndAuthor, GWL_USERDATA, DefStaticProc);

            ::SendMessage(hWndAuthor, WM_STARTSCROLL, 30, 0);

            ::SetWindowPos(hDlg, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            return TRUE;
        }
        case WM_COMMAND:
        {
            if(LOWORD(WParam) == IDOK || LOWORD(WParam) == IDCANCEL)
            {
                ::SendMessage(hWndAuthor, WM_STOPSCROLL, 0, 0);
                LONG DefStaticProc = GetWindowLong(hWndAuthor, GWL_USERDATA);
                SetWindowLong(hWndAuthor, GWL_WNDPROC, DefStaticProc);
                EndDialog(hDlg, LOWORD(WParam));
                return TRUE;
            }
            break;
        }
        case WM_CONTEXTMENU:
        {
            ::SendMessage(hWndAuthor, WM_CONTEXTMENU, WParam, LParam);
            return TRUE;
        }
    }
    return FALSE;
}

void AboutDlgModal(HWND hWndParent)
{
    static BOOL bPop = FALSE;
    if(!bPop)
    {
        bPop = TRUE;
        DialogBox(::GetModuleHandle(NULL), (LPCTSTR)IDD_ABOUTBOX, hWndParent, (DLGPROC)AboutDlgProc);
        bPop = FALSE;
    }
}