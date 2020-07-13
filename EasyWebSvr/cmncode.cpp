#include "stdafx.h"
#include "cmncode.h"

#ifndef INVALID_FILE_ATTRIBUTES
  #define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
#endif

// �ж�һ���ļ��Ƿ����
BOOL IsFileExist(const TCHAR *pFileName)
{
  DWORD Attr = GetFileAttributes(pFileName);
  if(Attr == INVALID_FILE_ATTRIBUTES)
    return FALSE;
  return (Attr & FILE_ATTRIBUTE_DIRECTORY) ? FALSE : TRUE;
}

// �ж�һ��Ŀ¼�Ƿ����
BOOL IsDirectoryExist(const TCHAR *pDirName)  
{
  DWORD Attr = GetFileAttributes(pDirName);
  if(Attr == INVALID_FILE_ATTRIBUTES)
    return FALSE;
  return (Attr & FILE_ATTRIBUTE_DIRECTORY) ? TRUE : FALSE;
}
