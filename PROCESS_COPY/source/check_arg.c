#include<process_copy.h>

int check_arg(int argc , const char* src, int prono){
	if(argc <3){
		printf("Fail\n");
		exit(0);
	}
	if((access(src,F_OK))!=0){
		printf("src no exit \n");
		exit(0);
	}
	return 0 ;




	
}
