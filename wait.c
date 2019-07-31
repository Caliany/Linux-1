//这是一个实现进程等待的demo，体会wait/waitpid两个接口的阻塞等待以及子进程的退出返回值的获取
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include <sys/wait.h>
int main(){
  int pid=fork();
  if(pid<0){
    //errno是一个全局变量，存储每次系统调用出现错误的原因编号
    //strerror,通过错误编号获取字符串错误原因
    printf("fork error:%s\n",strerror(errno));
    //perror:直接打印上一次调用错误的原因
    perror("fork error");
  }
  else if(pid == 0){
  sleep(3);
  exit(257);
     //
  }
  //pid_t wait(int *status);
  //阻塞等待任意一个字进程获取返回值
 // wait(NULL);
 // 
 // pid_t waitpid(pid_t pid, int *status, int options);
 // 阻塞等待任意一个子进程或者指定的子进程退出
 //pid：   -1等待任意的子进程  pid>0 :等待指定子进程   如果不存在这个子进程直接报错返回
 //options:WNOHANG 直接报错返回，将waitpid设置为非阻塞
  //返回值：若WNOHANG被指定，没有子进程退出则立即报错返回0；错误：返回-1
  //statu中低16位中的高8位储存子进程返回值，   低8位中的高1位储存core dump标志(核心转储)
  int statu;
  while (waitpid(-1,&statu,WNOHANG) == 0){
    //非阻塞轮询操作
  printf("drink coffee\n");
  sleep(1);
  }
  if((statu & 0x7f) == 0){
  printf("exit code:%d\n",(statu>>8)& 0xff);
  }
  while(1){
  printf("i am a parent\n");
  sleep(1);
  }
  
  return 0;
}
