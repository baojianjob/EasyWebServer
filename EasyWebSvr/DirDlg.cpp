// ѡ��Ŀ¼�Ի���
// wbj 2002.12.16
// wbj 2003.10.9
// wbj 2004.2.6

#include "stdafx.h"
#include <shlobj.h>

#include "dirdlg.h"

namespace minilib
{

CDirdlg::CDirdlg()
{
  PathName[0]   = 0;
  IniSelDir[0]  = 0;
}

CDirdlg::~CDirdlg()
{
}

// SHBrowseForFolder�ؼ��ڳ�ʼ����ѡ��ı��Ļص�����
int CALLBACK CDirdlg::BrowseCtrlCallback(HWND hWnd, UINT Msg, LPARAM LParam, LPARAM pData) // static
{
  CDirdlg *pDirDlg = (CDirdlg *)pData;
  if(Msg == BFFM_INITIALIZED && pDirDlg->IniSelDir[0])
  {
    ::SendMessage(hWnd, BFFM_SETSELECTION, TRUE, (LPARAM)(LPCTSTR)(pDirDlg->IniSelDir));
  }
  else // Msg == BFFM_SELCHANGED
  {
  }

  return 0;
}

BOOL CDirdlg::DoModal(HWND hWndParent, const TCHAR *pIniSelDir, const TCHAR *pDlgTitle)
{
  LPMALLOC pMalloc;
  if(SHGetMalloc(&pMalloc)!= NOERROR)
    return FALSE;

  BROWSEINFO Bi;
  memset(&Bi, 0, sizeof(BROWSEINFO));

  Bi.hwndOwner      = hWndParent;
  Bi.pszDisplayName = PathName;
  Bi.lpszTitle      = (pDlgTitle && *pDlgTitle) ? pDlgTitle : _T("��ѡ��Ŀ¼:");
  Bi.ulFlags        = BIF_RETURNONLYFSDIRS;
  Bi.lpfn           = BrowseCtrlCallback;   //�ص�������ַ
  Bi.lParam         = (LPARAM)this;

  if(pIniSelDir && pIniSelDir[0])
  {
    lstrcpyn(IniSelDir, pIniSelDir, sizeof(IniSelDir) / sizeof(TCHAR) - 1);

    int SelDirLen = lstrlen(IniSelDir);
    if(SelDirLen > 0 && IniSelDir[SelDirLen - 1] == _T('\\'))
      IniSelDir[SelDirLen - 1] = _T('\0');

    if(SelDirLen >= 2 && IniSelDir[1] == _T(':') && IniSelDir[2] == 0)  // �д��� Win98 �²���
      lstrcat(IniSelDir, _T("\\"));
  }
  else
  {
    IniSelDir[0] = 0;
  }

  ITEMIDLIST *pIdl = ::SHBrowseForFolder(&Bi);
  if(pIdl == NULL)
    return FALSE;

  BOOL bReturn = ::SHGetPathFromIDList(pIdl, PathName);

  pMalloc->Free(pIdl);
  pMalloc->Release();
  return bReturn;
} 

}