/*
 * =====================================================================================
 *
 *       Filename:  9-01sem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 13时45分40秒
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
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>

typedef union semun {
	int val;    
	struct semid_ds *buf;    
	unsigned short *array;  
	struct seminfo *__buf;  
}semun;

int main(){

	key_t key;
	int semid;
	semun v;
	int r;
	struct sembuf op[1];
	//create sem
	key = ftok(".",99);
	if(key == -1){
		printf("key error:%m\n");
		exit(-1);
	}
	//	semid = semget(key,1/* 信號量數組個數 */,
	//			IPC_CREAT|IPC_EXCL|0666);
	//	get sem
	semid = semget(key,1/* 信號量數組個數 */, 0);//
	if(semid == -1){
		printf("get semid error:%m\n");
		exit(-1);
	}
	printf("semid:%d\n",semid);

	//init sem
	v.val = 2;
	r = semctl(semid,0,SETVAL,v);
	if(r == -1){
		printf("init semid error:%m\n");
		exit(-1);
	}

	//阻塞sem
	op[0].sem_num = 0;
	op[0].sem_op = -1; //阻塞是減操作
	op[0].sem_flg = 0; 
	while(1){
		r =	semop(semid,op,1);
		if(r == -1){
			printf("init semid error:%m\n");
			exit(-1);
		}
		printf("解除阻塞!!!!!!\n");
	}

	//delete sem


	return 0;
}

