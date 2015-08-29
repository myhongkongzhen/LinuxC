/*
 * =====================================================================================
 *
 *       Filename:  5-07fork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 19时46分35秒
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
#include <unistd.h>

int main(){

	printf("create process before...\n");
	int pid = fork();

	if(pid == 0){
		while(1){
			printf("sub process execute...\n");
			sleep(1);
		}
	}else if(pid == -1){
		printf("create process fail!\n");
		sleep(1);
	}else{
		while(1){
			printf("factory process execute...\n");
			sleep(1);
		}
	}

	//	printf("create process finish (%d)!\n",pid);
	return 0;
}

