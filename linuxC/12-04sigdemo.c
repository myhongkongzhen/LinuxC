/*
 * =====================================================================================
 *
 *       Filename:  12-03cleanup.c
 *
 *    Description:   
 *
 *        Version:  1.0
 *        Created:  2014年08月27日 09时12分29秒
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
#include <sched.h>

sigset_t sigs;
pthread_t to;
pthread_t ta;

void* runo(void*d){
	int i;
	int s;
	for(i = 0 ;;i += 2){
		printf("%d\n",i);
		sched_yield();
		sigwait(&sigs,&s);
		//pthread_kill(to,34);
		printf("----%d\n",s);
	}
}

void* runa(void*d){
	int i;
	int s;
	for(i = 1 ;;i += 2){
		printf("%d\n",i);
		//		sched_yield();
		sleep(1);
		pthread_kill(to,34);
		//sigwait(&sigs,&s);
		//printf("----%d\n",s);
	}
}

int main(){

	sigemptyset(&sigs);
	sigaddset(&sigs,34);

	pthread_create(&to,0,runo,0);
	pthread_create(&ta,0,runa,0);

	pthread_join(to,(void**)0);
	pthread_join(ta,(void**)0);

	return 0;
}


