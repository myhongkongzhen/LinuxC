/*
 * =====================================================================================
 *
 *       Filename:  12-01createth.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月26日 20时47分02秒
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
#include <sched.h>

void call(){
	pthread_exit("kill");
	return ;
}

void* run(void* data){
	printf("Thread....\n");
	sched_yield();
	//	return "hello";
	pthread_exit("world");
}

int main(){

	pthread_t tid;
	char* re;
	pthread_create(&tid,0,run,0);

	pthread_join(tid,(void**)&re);
	printf("---%s\n",re);

	return 0;
}


