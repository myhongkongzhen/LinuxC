/*
 * =====================================================================================
 *
 *       Filename:  7-01sigmask.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 23时41分16秒
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
#include <signal.h>
#include <unistd.h>

void handle(int s){
	printf("處理用戶外部中斷...\n");
	sleep(2);
	printf("處理用戶外部中斷完畢\n");
}

int main(){

	int i = 0;

	sigset_t sigs;
	sigset_t sigt;
	sigset_t sigu;

	sigemptyset(&sigs);
	sigemptyset(&sigu);
	sigemptyset(&sigt);
	sigaddset(&sigs,SIGINT);

	signal(SIGINT,handle);

	sigprocmask(SIG_BLOCK,&sigs,0);

	for(i = 0 ; i < 10 ; i ++){
		printf("copy file : [%d]\n",i);
		sleep(3);//模擬真實的業務操作
		printf("copy file : [%d] complete\n",i);
		sigpending(&sigu);
		if(sigismember(&sigu,SIGINT)){
			sigsuspend(&sigt);
		}
	}

	sigprocmask(SIG_UNBLOCK,&sigs,0);
	printf("over!\n");

	return 0;
}

