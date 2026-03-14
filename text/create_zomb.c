#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;
	pid_t zpid;
	pid = fork();
	if(pid>0){
		printf("parent pid %d runing\n",getpid());
		//zpid =wait(NULL);
		while((zpid=waitpid(-1,NULL,WNOHANG))!=-1){
			if(zpid==0){
				//执行一次父进程任务
				printf("执行一次父进程\n");
				usleep(20000);//非阻塞轮询回收
			}else if(zpid>0){
				printf("回收成功，僵尸进程pid %d\n",zpid);
				break;
			}
		}
		//printf("parent wait sucess , zpid %d\n",zpid);
		while(1)
			sleep(1);
	}else if(pid==0){
		printf("child pid %d runing\n",getpid());
		sleep(5);
		exit(0);
	}else{
		perror("foek call failed");
		exit(0);
	}
	return 0;





}
