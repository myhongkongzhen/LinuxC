/*
 * =====================================================================================
 *
 *       Filename:  7-05sigaction.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 01时35分22秒
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
#include <signal.h>

void handle(int s){
	printf("!!!OOKK!!!\n");
	sleep(2);
	printf("!!!KK0000000!!!\n");
}

void handle2(int s,siginfo_t * info,void* d){
	printf("!!!OOKK!!%d!\n",info->si_int);
	sleep(2);
	printf("!!!KK0000000!!!\n");
}

int main(){

	struct sigaction act = {0};
	//act.sa_handler = handle;
	act.sa_sigaction = handle2;	
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGINT);
	//act.sa_flags = 0;
	act.sa_flags = SA_SIGINFO ;

	sigaction(SIGUSR1,&act,NULL);

	while(1);

	return 0;
}


