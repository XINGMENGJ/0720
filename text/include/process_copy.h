#include<stdio,h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

//参数检验
int check_arg(int argc,const char * src,int prono);
//任务量计算
int block_cur(const char* src ,int prono);
//进程创建
int process_create(const char * src , const char * dest ,int blocksize ,int prono);
