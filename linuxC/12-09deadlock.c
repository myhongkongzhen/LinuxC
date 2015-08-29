/*
 * =====================================================================================
 *
 *       Filename:  12-09deadlock.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月27日 12时35分03秒
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
#include <pthread.h>

pthread_t t1,t2;
pthread_mutex_t m1,m2;
pthread_cond_t c;

void* r1(void* d){
	while(1){
		pthread_mutex_lock(&m1);
		printf("wait..............\n");
		pthread_cond_wait(&c,&m2);
		pthread_mutex_unlock(&m1);
	}
}

void* r2(void* d){
	while(1){
		pthread_mutex_lock(&m1);
		printf("not wait..........\n");
		pthread_cond_signal(&c);
		pthread_mutex_unlock(&m1);
	}
}

int main(){

	pthread_cond_init(&c,0);

	pthread_mutex_init(&m1,0);
	pthread_mutex_init(&m2,0);

	pthread_create(&t1,0,r1,0);
	pthread_create(&t2,0,r2,0);

	pthread_join(t1,0);
	pthread_join(t2,0);

	pthread_mutex_destroy(&m2);
	pthread_mutex_destroy(&m1);

	pthread_cond_destroy(&c);

	return 0;
}

