//***********************************************
// �ļ����ƣ�basewnd.h
// �������ܣ����ڻ���
// �������ߣ�wbj
// �ա����ڣ�2003-4-19
// ��������: 2006-2-10
//***********************************************
#ifndef __BASEWND_H__
#define __BASEWND_H__
#pragma once

#pragma warning(disable:4312)

namespace minilib
{
class CmdTARGET;
typedef void (CmdTARGET::*MsgFUNC)();
typedef LONG (CmdTARGET::*WndMsgFUNC)(WPARAM, LPARAM);
typedef BOOL (CmdTARGET::*DlgMsgFUNC)(WPARAM, LPARAM);

enum WndFuncTYPE
{
  WFT_MESSAGE,
  WFT_COMMAND,
};

struct MSGMAP_ENTRY
{
  UINT          Message;  // ������Message��Ҳ������CommandId
  UINT          FuncType;
  MsgFUNC       MsgFunc;
};

struct MSGMAP
{
  const MSGMAP* (__stdcall *pfnGetBaseMap)();
  const MSGMAP_ENTRY   *pEntries;
};

// ������Ϣӳ��
#define DECLARE_MESSAGE_MAP() \
  protected: \
    static const MSGMAP* __stdcall GetThisMessageMap(); \
    virtual const MSGMAP* GetMessageMap() const; \

// ��ʼ��Ϣӳ��
#define BEGIN_MESSAGE_MAP(TheClass, BaseClass) \
  const MSGMAP* TheClass::GetMessageMap() const \
  { \
    return GetThisMessageMap(); \
  } \
  const MSGMAP* __stdcall TheClass::GetThisMessageMap() \
  { \
    typedef TheClass ThisClass; \
    typedef BaseClass TheBaseClass; \
    static const MSGMAP_ENTRY _MessageEntries[] =  \
    { \

// ������Ϣӳ��
#define END_MESSAGE_MAP() \
      { 0, 0, NULL } \
    }; \
    static const MSGMAP MessageMap = \
    { \
      &TheBaseClass::GetThisMessageMap, \
      &_MessageEntries[0] \
    }; \
    return &MessageMap; \
  } \

class BaseWND;
typedef void (BaseWND::*MsgFUNCW)(void);

//
#define ON_MESSAGE(MsgId, MsgFunc) \
  { MsgId, WFT_MESSAGE, (MsgFUNC)(MsgFUNCW)(static_cast<LONG (BaseWND::*)(WPARAM, LPARAM)>(&ThisClass::MsgFunc)) }, \

//
#define ON_COMMAND(CmdId, MsgFunc) \
  { CmdId, WFT_COMMAND, (MsgFUNC)(MsgFUNCW)(static_cast<LONG (BaseWND::*)(WPARAM, LPARAM)>(&ThisClass::MsgFunc)) }, \


#define ON_DLGMESSAGE(MsgId, MsgFunc) \
  { MsgId, WFT_MESSAGE, (MsgFUNC)(MsgFUNCW)(static_cast<BOOL (BaseWND::*)(WPARAM, LPARAM)>(&ThisClass::MsgFunc)) }, \

#define ON_DLGCOMMAND(CmdId, MsgFunc) \
  { CmdId, WFT_COMMAND, (MsgFUNC)(MsgFUNCW)(static_cast<BOOL (BaseWND::*)(WPARAM, LPARAM)>(&ThisClass::MsgFunc)) }, \

class CmdTARGET
{
protected:
  DECLARE_MESSAGE_MAP()
};

class BaseWND : public CmdTARGET
{
public:
  HWND          m_hWnd;
  BOOL          bDeleteThis;

public:
  BaseWND();
  virtual ~BaseWND();
  operator HWND() const;

public:
  BOOL          CreateEx(DWORD ExStyle, LPCTSTR ClassName, LPCTSTR WindowName, DWORD Style,
                         int Left, int Top, int Width, int Height, 
                         HWND hWndParent, HMENU IDorHMenu);
  BOOL          SubclassWindow(HWND hWnd);
  BOOL          SubclassDlgItem(HWND hDlg, UINT DlgItemID);
  HWND          UnsubclassWindow();

  BOOL          Attach(HWND hWndNew);
  HWND          Detach();

  BOOL          ShowWindow(int CmdShow);
  BOOL          UpdateWindow();

protected:
  virtual BOOL  OnWndMsg(UINT Message, WPARAM WParam, LPARAM LParam, LRESULT *pResult);
  virtual BOOL  OnChildNotify(UINT Message, WPARAM WParam, LPARAM LParam, LRESULT *pResult);
  virtual void  PreRegisterClass(WNDCLASSEX *pWcex);
  virtual void  PreSubclassWindow();
  virtual LRESULT CALLBACK WindowProc(UINT Message, WPARAM WParam, LPARAM LParam);
  virtual LRESULT CALLBACK DefWindowProc(UINT Message, WPARAM WParam, LPARAM LParam);
  const MSGMAP_ENTRY *FindMessageEntry(UINT Message, WPARAM WParam);

  LONG          OnDrawItem(WPARAM WParam, LPARAM LParam);
  static BaseWND *GetWndFromHandle(HWND hWnd);

private:
  WNDPROC       OrgWndProc;
  ATOM          RegisterWndClass(HINSTANCE hInst, LPCTSTR ClassName);
  static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT Message, WPARAM WParam, LPARAM LParam);

  DECLARE_MESSAGE_MAP()
};

inline BaseWND::operator HWND() const
{ 
  return this == NULL ? NULL : m_hWnd; 
}

inline BaseWND *BaseWND::GetWndFromHandle(HWND hWnd)
{
  return (BaseWND *)::GetWindowLong(hWnd, GWL_USERDATA);
}

inline LRESULT CALLBACK BaseWND::DefWindowProc(UINT Message, WPARAM WParam, LPARAM LParam)
{
  assert(OrgWndProc != NULL);
  return CallWindowProc(OrgWndProc, m_hWnd, Message, WParam, LParam);
}

inline BOOL BaseWND::ShowWindow(int CmdShow) 
{ 
  return ::ShowWindow(m_hWnd, CmdShow); 
}

inline BOOL BaseWND::UpdateWindow()
{ 
  return ::UpdateWindow(m_hWnd); 
}

///////////////////////////////////////////////////////////////////////////////

//BOOL GlobalRegisterClass(const TCHAR *pClassName);

void MakePoint(POINT *pPt, LPARAM LParam);

// �ѵ�ǰ�ͻ�������ת������Ļ����
void ClientToScreen(HWND hWnd, RECT *pRect);

// ����Ļ����ת���ɵ�ǰ�ͻ�������
void ScreenToClient(HWND hWnd, RECT *pRect);

// �ѵ�ǰ�ͻ�������ת���ɸ����ڿͻ�������
void ClientToParent(HWND hWnd, POINT *pPos);

// �ѵ�ǰ�ͻ�������ת���ɸ����ڿͻ�������
void ClientToParent(HWND hWnd, RECT *pRect);

// ������
void FillRect(HDC hDc, const RECT *pRect, COLORREF Color);

// �� XOR ��ʽ������
void FillFocusRect(HDC hDc, CONST RECT *pRect);

// ���д���
BOOL CenterWindow(HWND hWnd, HWND hWndCenter = NULL);

}
#pragma warning(default:4312)

#endif // __BASEWND_H__