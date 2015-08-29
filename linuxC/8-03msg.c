/*
 * =====================================================================================
 *
 *       Filename:  8-03msg.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 10时43分19秒
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
#include <fcntl.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct msgbuf{
	long type;
	char data[100];
}msgbuf;

int main(){

	key_t key;
	int msgid;
	int i;

	//create
	key = ftok(".",204);	
	if(key == -1){
		printf("ftok error:%m\n");
		exit(-1);
	}

	msgid = msgget(key,IPC_CREAT|IPC_EXCL|0666);
	if(msgid == -1){
		printf("msgget error:%m\n");
		exit(-1);
	}

	//make msg
	msgbuf msg;
	//send
	for(i = 0 ; i < 10 ; i ++){
		msg.type = 1;
		bzero(msg.data,sizeof(msg.data));
		sprintf(msg.data,"Msg:%d",i);
		msgsnd(msgid,&msg,strlen(msg.data),0);
	}	
	for(i = 0 ; i < 10 ; i ++){
		msg.type = 2;
		bzero(msg.data,sizeof(msg.data));
		sprintf(msg.data,"Msg 2 :%d",i);
		msgsnd(msgid,&msg,strlen(msg.data),0);
	}	
	//delete
	msgctl(msgid,IPC_RMID,0);	
	return 0;
}

