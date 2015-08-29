/*
 * =====================================================================================
 *
 *       Filename:  6-09mask.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 21时54分33秒
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

void h(int s){
	printf("抽空處理int信號\n");
}

int main(){
	int sum = 0;
	int i;

	sigset_t sigs;
	sigset_t sigp;
	sigset_t sigq;


	sigemptyset(&sigs);
	sigemptyset(&sigp);
	sigemptyset(&sigq);

	signal(SIGINT,h);
	sigaddset(&sigs,SIGINT);

	sigprocmask(SIG_BLOCK,&sigs,0);

	for(i = 1 ; i <= 10 ; i++){
		sum += 1;
		printf("%d\n",sum);
		sigpending(&sigp);
		if(sigismember(&sigp,SIGINT)){
			printf("SIGINT is queue....\n");
			sigsuspend(&sigq);
		}
		sleep(1);
	}
	printf("----%d\n",sum);
	sigprocmask(SIG_UNBLOCK,&sigs,0);
	printf("over!\n");
	while(1);

	return 0;
}

