// ѡ��Ŀ¼�Ի���
// wbj 2002.12.16
// wbj 2003.10.9
// wbj 2004.2.6

namespace minilib
{

class CDirdlg
{
public:
  CDirdlg();
  virtual ~CDirdlg();

  BOOL DoModal(HWND hWndParent,                 // �����ھ��
               const TCHAR *pIniSelDir = NULL,  // ��ʼѡ�е�Ŀ¼(����·��)
               const TCHAR *pDlgTitle = NULL    // ��ʾ����
              );

  const TCHAR *GetDirPathName() { return PathName; }

protected:
  TCHAR  PathName[MAX_PATH];  // ��ŷ��ص�·����Ϣ
  TCHAR  IniSelDir[MAX_PATH]; // ��ʼѡ�е�Ŀ¼��

  static int CALLBACK BrowseCtrlCallback(HWND, UINT, LPARAM, LPARAM);
};

}