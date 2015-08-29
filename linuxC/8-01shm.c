/*
 * =====================================================================================
 *
 *       Filename:  8-01shm.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 06时40分23秒
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
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int *p;
key_t key;
int shmid;

void deal(int s){
	if(s == SIGINT){
		//4.shmdt
		shmdt(p);	
		//5.shctl
		shmctl(shmid,IPC_RMID,NULL);	
		exit(-1);
	}
}

int main(){

	signal(SIGINT,deal);
	int i;
	//1.shmget
	key = ftok(".",255);	
	if(key == -1){
		printf("f to k error :%m\n");
		exit(-1);
	}
	shmid = shmget(key,4,IPC_CREAT|IPC_EXCL|0666);
	if(shmid == -1){
		printf("shmget error :%m\n");
		exit(-1);
	}
	//2.shmat
	p = shmat(shmid,0,0);	
	if(p == (int*)-1){
		printf("shmat error :%m\n");
		exit(-1);
	}
	//3
	while(1){	
		*p = i++;	
		sleep(1);
	}
	return 0;
}

