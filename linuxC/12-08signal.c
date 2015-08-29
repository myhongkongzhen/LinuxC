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

pthread_t t1;
pthread_t t2;

pthread_cond_t ct;
pthread_mutex_t mt;

void* r1(void* d){
	int s;
	while(1){
		sleep(1);
		pthread_cond_wait(&ct,&mt);
		printf("~~~~~~~%d~~~~~~~\n",s);
	}
}

void* r2(void* d){
	while(1){
		pthread_cond_signal(&ct);
		pthread_cond_signal(&ct);
		pthread_cond_signal(&ct);
		sleep(2);
	}
}

int main(){

	pthread_mutex_init(&mt,0);
	pthread_cond_init(&ct,0);

	pthread_create(&t1,0,r1,0);
	pthread_create(&t2,0,r2,0);

	pthread_join(t1,(void**)0);
	pthread_join(t2,(void**)0);

	pthread_cond_destroy(&ct);
	pthread_mutex_destroy(&mt);

	return 0;
}

