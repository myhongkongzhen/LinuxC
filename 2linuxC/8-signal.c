/*
 * =====================================================================================
 *
 *       Filename:  8-signal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 21时03分09秒
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
#include <fcntl.h>
#include <signal.h>

void handle(int s){
	printf("外部中斷處理start....\n");
	sleep(1);
	printf("外部中斷處理complete....\n");
}

int main(){

	sigset_t sigs,sigt,sigu;
	sigemptyset(&sigs);
	sigemptyset(&sigu);
	sigemptyset(&sigt);
	sigfillset(&sigs);

	signal(SIGINT,handle);

	sigprocmask(SIG_BLOCK,&sigs,NULL);
	int i;
	for(i = 0 ; i < 10 ; i ++){
		printf("正在拷貝視頻文件%d....\n",i);
		sleep(2);
		printf("拷貝視頻文件complete....\n");
		sleep(1);
		sigpending(&sigu);
		if(sigismember(&sigu,SIGINT)){
			sigsuspend(&sigt);
		}
	}
	printf("所有拷貝視頻文件complete....\n");
	sigprocmask(SIG_UNBLOCK,&sigs,NULL);

	return 0;
}

