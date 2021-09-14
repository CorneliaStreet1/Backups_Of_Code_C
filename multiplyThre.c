#include<windows.h>     // 线程函数需要操作系统的函数
#include<process.h>        // 线程函数头文件
#include<stdio.h>
unsigned __stdcall getInput (void* pArguments);
int main(){
   HANDLE hThread1;       // 句柄
   unsigned ThreadID=1;    // 线程的标识号
   hThread1=(HANDLE) _beginthreadex(NULL, 0, getInput,NULL, 0, &ThreadID);    // 创建一个getInput函数的线程 
   printf("main thread is running\n");   //主线程输出
   WaitForSingleObject(hThread1, INFINITE);  //等子线程结束
   CloseHandle (hThread1);  //无须控制线程时，则用该语句删
                                                 // 除句柄。
 }
unsigned __stdcall getInput (void* pArguments)
// 线程函数的返回值是指定类型，形参也只能有一个
{
	printf("hThreadl is running\n"); //自定义的函数体

     	_endthreadex(0);  // 结束线程
	return 0;
}
