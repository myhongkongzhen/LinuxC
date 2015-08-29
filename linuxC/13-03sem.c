/*
 * =====================================================================================
 *
 *       Filename:  13-03sem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月27日 14时13分34秒
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
#include <semaphore.h>

sem_t sem;

void* run(void* d){
	while(1){
		sem_wait(&sem);
		printf("wait..............\n");
	}
}

int main(){

	pthread_t tid;

	sem_init(&sem,0,5);

	pthread_create(&tid,0,run,0);

	while(1){
		sleep(1);
		sem_post(&sem);
	}

	return 0;
}

