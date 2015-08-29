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

pthread_mutex_t m;

void handle(void* data){
	printf("thread [%s] exit........\n",data);
	pthread_mutex_unlock(&m);
}

void* runo(void*d){
	int i;
	for(i = 0 ;;i += 2){
		pthread_mutex_lock(&m);
		printf("%d\n",i);
		pthread_mutex_unlock(&m);
	}
}

void* runa(void*d){
	int i;
	for(i = 1 ;;i += 2){
		pthread_mutex_lock(&m);
		pthread_cleanup_push(handle,"runa");
		printf("%d\n",i);
		pthread_cleanup_pop(0);
		pthread_mutex_unlock(&m);
	}
}

int main(){

	pthread_t to;
	pthread_t ta;

	pthread_mutex_init(&m,0);
	pthread_create(&to,0,runo,0);
	pthread_create(&ta,0,runa,0);

	sleep(1);
	pthread_cancel(ta);
	pthread_join(to,(void**)0);
	pthread_join(ta,(void**)0);
	pthread_mutex_destroy(&m);

	return 0;
}


