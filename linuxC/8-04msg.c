
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

	msgid = msgget(key,0);
	if(msgid == -1){
		printf("msgget error:%m\n");
		exit(-1);
	}

	//make msg
	msgbuf msg;
	//send
	while(1){
		bzero(&msg,sizeof(msg));
		msg.type = 1;
		msgrcv(msgid,&msg,sizeof(msg.data),1,0);
		printf("%s\n",msg.data);
	}	
	return 0;
}

