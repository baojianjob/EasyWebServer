// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���ǳ��õ��������ĵ���Ŀ�ض��İ����ļ�
//

#pragma once

//#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ���
#include <winsock2.h>
#include <windows.h>
// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: �ڴ˴����ó���Ҫ��ĸ���ͷ
#include <stdio.h>
#include <commctrl.h>
#include <assert.h>
#include <process.h>

#include "core_log.h"

#define  ARRAY_SIZE(x)  (sizeof(x) / sizeof(x[0]))

#ifdef _DEBUG
  #define VERIFY(f)     assert(f)
#else
  #define VERIFY(f)     ((void)(f))
#endif

#define APP_TITLE       _T("EasyWebServer") 
