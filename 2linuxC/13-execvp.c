/*
 * =====================================================================================
 *
 *       Filename:  13-execvp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 12时42分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){

	if(fork()){
		sleep(10);
	}else{
		char* argv[4] = {"main","aa","bb",NULL};
		execvp("main",argv);
		printf("not found cmdline!\n");
		return -1;
	}

	return 0;
}

