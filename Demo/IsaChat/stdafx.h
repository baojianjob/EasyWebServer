// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���ǳ��õ��������ĵ���Ŀ�ض��İ����ļ�
//

#pragma once
#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�:
#include <windows.h>
#include <tchar.h>
#include <process.h>
#include <httpext.h>
#include <assert.h>
#include <vector>
#include <list>
using namespace std;

//#define _LOGDEBUG
#if defined _LOGDEBUG
    #define LOG_INFO(x) OutputDebugString(x)
#else
    #if _MSC_VER >= 1300
    #define LOG_INFO(x) __noop  
    #else
    #define LOG_INFO(x) ((void)0)
    #endif
#endif