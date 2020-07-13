#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>

#define TEST_FUNC  1

void main(int argc, char **argv)
{
#if (TEST_FUNC == 1)

    printf("Content-Type: text/html\n\n");
    printf("<html><head><title>CGI Demo</title></head>\n");
    printf("<body bgcolor=\"#000000\" text=\"#FFFFFF\">\n");
    printf("<br><center><h1>Hello World, CGI!</h1></center>\n");
    printf("</body></html>\n");

#elif (TEST_FUNC == 2)

    printf("Status: 300 test\nContent-Type: text/html\nContent-Length: 1\nContent:\n\n");
    printf("<html><head><title>CGI Demo</title></head>\n");
    printf("<body bgcolor=\"#000000\" text=\"#FFFFFF\">\n");
    printf("<br><center><h1>Hello World CGI!</h1></center>\n");
    printf("</body></html>\n");

#elif (TEST_FUNC == 3)

    //printf("Location: /index.htm\n\n");
    //printf("Content-Type: text/plain\nStatus: 300 test\n\n");
    printf("<html><head><title>CGI Demo</title></head>\n");
    printf("<body bgcolor=\"#000000\" text=\"#FFFFFF\">\n");
    for(int i = 0; i < 10; i++)
        printf("<br><center><h1>Hello World CGI!</h1></center>\n");
    printf("</body></html>\n");

#elif (TEST_FUNC == 4)

    printf("Content-Type: text/html\n\n");
    for(TCHAR **pVariable = _tenviron; *pVariable; pVariable++ )
        printf("%s\n", *pVariable);

    printf("argc=%d\n", argc);
    for(int i = 0; i < argc; i++)
        printf("argv[%d]=%s\n", i, argv[i]);
    char CurDir[300];
    ::GetCurrentDirectory(300, CurDir);
    printf("CurDir=%s\n", CurDir);

#else
    #error not code.
#endif;
}
/*
IIS 5.1��CGI���������Ĵ������
1. ����\r\n\r\n�����û���ҵ��������502��������ҵ���������ͷ�����º���������
2. �������Status�У�����ȡStatus�����ݣ���Ϊ���ص�HTTP/1.1�е����ݣ����û���ҵ�Status�У�����Ϊ200 OK
3. �������ͷ����Location�У�������������еģ�����Status���������ݣ�����ȫ���Լ��ϳɵ�����"302 Object Moved"
4. �������Conteng-Length�У�ȡ��ֵ����Ϊ0��ȡֵʧ�ܣ���ȡ���������ݵ������ֻ���ͷ
5. �����������в���ʶ���У�����Content-Type��Connection��Server��HTTP/1.1�ȣ�����ȡ������ȫ���ŵ�ͷ�����
6. ����CGI�������Connection�ֶΣ�ȫ���������Connection: close
7. CGI�е�Status��Location�ȶ�����д�ڵ�һ��
8. ����ҵ����Status�У���Location�У����������һ��Ϊ׼
//Status��ǰLocation�ں���LocationΪ׼��Location��ǰStatus�ں���StatusΪ׼�����Location����һ����ͨ��
*/