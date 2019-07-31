#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(){
  while(1){
    printf("[minishell]$:");
    fflush(stdout);

  char temp[1024]={0};
  scanf("%[^\n]%*c",temp);
  printf("[%s]\n",temp);

  int pid=fork();
  if(pid==0){
  execlp(temp,temp,NULL);
  //若子进程程序替换失败，则直接退出，因为终端不需要多个shell
  exit(0);
  }
  //等待子进程退出，避免成为僵尸进程
  wait(NULL);
  }
  return 0;
}
