#pragma once

class TextMSG
{
public:
  TCHAR         Name[8];      // ����
  BOOL          bSex;         // �Ա�
  TCHAR         Mail[32];     // �ʼ�
  SYSTEMTIME    Time;         // ʱ��
  int           TextLen;      // ���ݳ���
  TCHAR        *pText;        // ����

public:
  TextMSG();
  ~TextMSG();

  BOOL          ReadFile(FILE *pFile, int MaxTextLen = 1024 * 8);
  BOOL          WriteFile(FILE *pFile);
};
