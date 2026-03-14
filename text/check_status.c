/*======================================================
 * File Name: check_status.c
 * Author: XINGMENG
 * Created Time: 2026-03-13 06:30:38
 * Description: 
 ======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int i;
    for(i=0;i<2;i++){
        pid =fork();
        if(pid==0){
            break;
        }
    }
    if(pid>0){
        printf("parent pid %d\n, waiting\n",getpid());
        pid_t zpid;
        int status;
        while((zpid=waitpid(-1,&status,WNOHANG))!=-1){
            if(zpid ==0){

            }else if(zpid>0){
                if(WIFEXITED(status)){
                    printf("zombie process %d , 正常退出 返回值 %d\n",zpid,WEXITSTATUS(status));

                }if(WIFSIGNALED(status)){
                        printf("zombie process %d , 异常退出 信号编号 %d\n",zpid,WTERMSIG(status));

                }
            }
        }
    }else if(pid==0){
        if(i==0){
            printf("child %d pid %d\n,runing...\n",i,getpid());
            sleep(5);
            printf("child %d pid %d\n,exiting...\n",i,getpid());
            exit(6);
        }else if(i==1){
            printf("child %d pid %d\n,runing...\n",i,getpid());
            while(1)
                sleep(1);
        }
    }else{
        perror("fork call faild");
        exit(0);
    } 

    return 0;

}
