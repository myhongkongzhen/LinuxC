/*
 * =====================================================================================
 *
 *       Filename:  12-demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 11时30分21秒
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
#include <string.h>
#include <signal.h>

void handle(int s){
	pid_t cid = wait(NULL);
	printf("###child pid:%d\n",cid);
}

int main(){

	printf("old pid:%d\n",getpid());

	int id = 0;
	while(1){
		if(fork()){
			//signal(SIGCHLD,handle);
			if(id++<1){
				continue;
			}
			int i;
			for(i = 0 ; i < 3; i ++){
				printf("::%d==%d\n",getpid(),getppid());
				sleep(1);
			}
			printf("===parent exit===\n");
			sleep(10);
			break;
		}else{
			int i;
			for(i = 0 ; i < 4; i ++){
				printf("::%d==%d\n",getpid(),getppid());
				sleep(1);
			}
			printf("----child exit----\n");
			break;
		}
	}

	printf("---------exit-----------\n");

	return 0;
}

