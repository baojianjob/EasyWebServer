// ϵͳ������
// wbj 2003.3
#ifndef __SYSTEMTRAY_H__
#define __SYSTEMTRAY_H__

namespace minilib
{

class CSystemTray
{
public:
  CSystemTray();
  virtual ~CSystemTray();

  bool Create(HWND hWndParent, UINT CallbackMessage, const TCHAR *pToolTip, 
              HICON hIcon, UINT MenuIDResource);

  virtual void OnTrayNotification(WPARAM WParam, LPARAM LParam);

  void SetMenuItemDoubleClick(UINT MenuItemId) { m_nDbClickMenuItem = MenuItemId; }  // ˫��ͼ��ʱ��Ӧ�Ĳ˵���
  void SetMenuItemLeftClick(UINT MenuItemId) { m_nLeftClickMenuItem = MenuItemId; }  // �������ͼ��ʱ��Ӧ�Ĳ˵���

  void RemoveIcon();   // �ڳ����˳�ʱɾ������ͼ��
  bool SetIcon(HICON hIcon);
  bool SetIcon(UINT IconIDResource);

  bool CreateIconList(UINT FirstIconID, UINT LastIconID);
  bool BeginAnimate(UINT DelayMilliSeconds);
  void StopAnimate();

  bool SetTooltipText(const TCHAR *pToolTips);
  const TCHAR *GetTooltipText() const { return m_Nid.szTip; };

protected:
  static CSystemTray *pThis;
  static void CALLBACK AnimateTimerProc(HWND hWnd, UINT Msg, UINT_PTR IdEvent, DWORD Time);

  NOTIFYICONDATA m_Nid;
  UINT          m_nDbClickMenuItem;
  UINT          m_nLeftClickMenuItem;

  HICON        *pIconList;
  int           m_nIconCount;
  UINT_PTR      m_nTimerId;
};
 
}
#endif // __SYSTEMTRAY_H__