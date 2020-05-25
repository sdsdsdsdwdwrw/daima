#include <stdio.h>   


DWORD WINAPI ThreadFun(LPVOID pM)
{
	printf("子线程的线程ID号为：%d\n子线程输出Hello World\n", GetCurrentThreadId());
	return 0;
}
 
int main()
{
	printf("     最简单的创建多线程实例\n");
	

	HANDLE handle = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
	WaitForSingleObject(handle, INFINITE);
	return 0;
}
