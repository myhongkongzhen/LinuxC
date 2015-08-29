/*
 * =====================================================================================
 *
 *       Filename:  5-09parentchild.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 21时45分04秒
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
#include <sys/wait.h>
#include <signal.h>

void deal(int s){
	int status;
	printf("child......\n");
	wait(&status);
	printf("child(%d) over.\n",WEXITSTATUS(status));
}

int main(){
	if(fork()){
		signal(17,deal);
		//		signal(SIGCHLD,deal);
		while(1){
			printf("parent.\n");
			//int status;
			//wait(&status);
			//printf("child(%d) over.\n",WEXITSTATUS(status));
			sleep(3);
		}
	}else{
		printf("child.\n");
		sleep(1);
		exit(88);
	}
	return 0;
}

