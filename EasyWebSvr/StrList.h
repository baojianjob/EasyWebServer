//***********************************************
// �ļ����ƣ�strlist.h
// �������ܣ��ַ�������
// �������ߣ�wbj
// �������ڣ�2002-12-22
// �������ڣ�2003-11-26
//***********************************************
#ifndef __STRLIST_H__
#define __STRLIST_H__

#include "mtstring.h"
#include "tlist.h"

namespace minilib
{

class StrLIST : public TLIST<MtSTRING>
{
public:
  // ���ַ���ת�����ַ�������, �� \r\n ���ָ�
  void FromStringToList(const TCHAR *pString);

  // ���ַ���ת�����ַ�������, �� pSeparator �е��ַ����ָ�
  void FromStringToList(const TCHAR *pString, const TCHAR *pSeparator);

  // ���ַ�������ת�����ַ���, �� pSeparator ���ָ�
  void FromListToString(MtSTRING &Str, const TCHAR *pSeparator = _T("\r\n")) const;

  // ��ȡ�ļ����ַ�������
  bool LoadFromFile(const TCHAR *pFileName);

  // ���ַ�����������ݱ��浽�ļ�
  bool SaveToFile(const TCHAR *pFileName) const;

  // ɾ�����������еĿ��ַ����ڵ�
  void RemoveNullString();

  // �Զ�����.  ע�⣺�� Unicode �汾���������⣬�д��Ľ�
  void AutoBreakLineStr(const TCHAR *pString, int MaxLineLength);
};

typedef StrLIST::POSITION StrListPOS;

}
#endif // __STRLIST_H__