#include<stdio.h>
#include<unistd.h>

int main(){
  printf("hello bit-----pid:%d\n",getpid());
//  pid_t fork(void);
//  创建一个子进程，父进程返回子进程的pid，子进程返回0；
  pid_t pid=fork();
  if(pid<0){
    printf("pid error\n");
    return -1;
  }
  else if(pid ==0){
    printf("------i am child-----:%d\n",getpid());
  }
  else{
    printf("------i am parent----:%d\n",getpid());
  }
  printf("hello world---pid:%d\n",getpid());
  while(1){
  printf("jin tian hao re!!!\n");
  sleep(1);
  }
  return 0;
}
