/*
 * =====================================================================================
 *
 *       Filename:  12-05signal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月27日 10时57分14秒
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
#include <pthread.h>
#include <signal.h>
#include <sched.h>

pthread_t t1;
pthread_t t2;

sigset_t sigs;

void* r1(void* d){
	int s;
	while(1){
		sigwait(&sigs,&s);
		printf("~~~~~~~%d~~~~~~~\n",s);
	}
}

void* r2(void* d){
	while(1){
		sched_yield();
		pthread_kill(t1,34);
	}
}

int main(){

	sigemptyset(&sigs);
	sigaddset(&sigs,34);

	pthread_create(&t1,0,r1,0);
	pthread_create(&t2,0,r2,0);

	pthread_join(t1,(void**)0);
	pthread_join(t2,(void**)0);

	return 0;
}

