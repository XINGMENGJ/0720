#include<process_copy.h>

int block_cur(const char* src,int prono){
	int fd;
	int filesize;
	if(fd = open(src,O_RDONLY==-1)){
		perror(" block_cur Failedd open error");
		exit(0);
	
	}if((filesize=lseek(fd,0,SEEK_END))==-1){
		perror(" block_cur lseek call error");
		exit(0);
	
	}

	if(filesize % prono ==0)
	return filesize/prono;
	else
	return filesize/prono +1;
}
