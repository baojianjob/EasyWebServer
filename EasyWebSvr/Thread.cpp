// ���̷߳�װ��
// wbj 2004.1.15
// wbj 2004.6.15

#include "stdafx.h"
#include "thread.h"

namespace minilib
{

BOOL CBaseThread::Start()
{
  if(hThread != INVALID_HANDLE_VALUE)
  {
    // assert(false);
    ::CloseHandle(hThread);
  }

  unsigned int ThreadID = 0;
  hThread = (HANDLE)::_beginthreadex(0, 0, ThreadFunction, (void*)this, 0, &ThreadID);

  return hThread != INVALID_HANDLE_VALUE;
}

BOOL CBaseThread::Wait(DWORD TimeoutMillis /* = INFINITE */) const
{
  DWORD Result = ::WaitForSingleObject(hThread, TimeoutMillis);

  if(Result == WAIT_OBJECT_0)
    return TRUE;
  else if(Result == WAIT_TIMEOUT)
    return FALSE;  // timeout
  else
    return FALSE;  // other error
}

unsigned int __stdcall CBaseThread::ThreadFunction(void *pData)
{
  CBaseThread *pThis = (CBaseThread *)pData;
  assert(pThis != NULL);

  int Result = 0;
  if(pThis)
  {
    Result = pThis->RunProc();
    //_endthreadex(Result);
  }

  return Result;
}

}
/*
�̵߳Ļ���֪ʶ��

1. �߳���������������ɵģ�һ�����̵߳��ں˶�����һ�����̶߳�ջ
2. ����ʱ�����õģ���������ִ���κζ�������ֻ���̵߳��������̵߳Ŀ����Ƚ����ٵö�
3. ͨ������£�һ��Ӧ�ó���ӵ��һ���û������̣߳����ڴ������д��ڣ�������һ��
   GetMessageѭ���������е����������̶߳��ǹ����̣߳����ǴӲ���������
4. CreateThread���������������̵߳�Windows��������������������ڱ�дC/C++���룬
   ����Ӧ�õ���CreateThread���෴��Ӧ��ʹ��Visual C++�����ڿ⺯��_beginthreadex
5. ����CreateThread�󣬷����߳̾�����������ʹ�ã�Ӧ����CloseHandle�����ر�
6. CreateThread�����һ������pdwThreadID����Windows2000/NT�¿��Դ���NULL��������
   Windows95/98�£����봫��һ����Ч��DWORD��ֵַ
7. Ҫ��ֹ�̵߳����У���õķ����ǣ��̺߳������ء�����ȷ�������߳���Դ����ȷ����
   ����Ψһ�취
8. ��ֹ�̵߳����У�Ҳ������ExitThread���������ַ�����ֹ�߳�ʱ������ϵͳ�������
   ���߳�ʹ�õ����в���ϵͳ��Դ������C++��Դ����C++���󣩽�����������ExitThread
   ������Windows���������̵߳ĺ����������дC/C++���룬����Ӧ�õ���ExitThread��
   Ӧ��ʹ��Visual C++�����ڿ⺯��_endthreadex
9. ��ֹ�̵߳����У�Ҳ������TerminateThread��������������ܹ������κ��̡߳�ע����
   ��һ���첽���еĺ�����Ҳ����˵��������ϵͳ����Ҫ�߳���ֹ���У����ǵ���������
   ʱ�����ܱ�֤�̱߳������������Ҫȷ�е�֪�����߳��Ѿ���ֹ���У��������
   WaitForSingleObject�������Ƶĺ����������̵߳ľ�������õ����Ӧ�ô�����ʹ����
   ����������Ϊ����ֹ���е��߳��ղ�������������֪ͨ���̲߳�����ȷ����������Ҳ�
   �ܷ�ֹ�Լ�������
10.��ʹ�÷��ػ����ExitThread�ķ��������߳�ʱ�����̵߳��ڴ��ջҲ�����������ǣ�
   ���ʹ��TerminateThread����ô��ӵ���̵߳Ľ�����ֹ����֮ǰ��ϵͳ���������̵߳�
   ��ջ�����⣬���߳���ֹ����ʱ��DLLͨ���յ�֪ͨ�������TerminateThreadǿ���߳�
   ��ֹ��DLL�Ͳ����յ�֪ͨ
11.���߳���ֹ����ʱ�����Ĳ������߳�ӵ�е������û���������ͷţ�ϵͳ�Զ���������
   �̵��κδ��ڣ�����ж�ظ��̴߳����Ļ�װ���κιҹ����̵߳��˳������
   STILL_ACTIVE��Ϊ���ݸ�ExitThread��TerminateThread�Ĵ��룻�̵߳��ں˶���״̬��
   Ϊ��֪ͨ������߳��ǽ��������һ����̣߳�ϵͳҲ��������Ϊ�Ѿ���ֹ���У���
   �̵��ں˶���ʹ�ü����ݼ� 1
12.һ���߳���ֹ���У��̵߳ľ����������Ч��Ȼ������߳̿��Ե���GetExitcodeThread
   �������hTread��ʶ���߳��Ƿ��Ѿ���ֹ����
*/