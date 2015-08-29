/*
 * =====================================================================================
 *
 *       Filename:  10-03democlient.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 21时21分53秒
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
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main(){

	int sfd;
	int cfd;
	int ffd;
	int r;
	int len;
	char buf[128];
	char filename[100];
	struct sockaddr_in dr;

	//1.create socket
	sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd == -1){
		printf("create socket error : %m\n");
		exit(-1);
	}
	printf("create socket success....\n");

	//2.bind ip address & port
	dr.sin_family = AF_INET;
	dr.sin_port = htons(8888);
	dr.sin_addr.s_addr = inet_addr("192.168.137.3");
	r = bind(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r == -1){
		printf("bind socket error : %m\n");
		exit(-1);
	}
	printf("bind socket success....\n");

	//3.listen
	r = listen(sfd,10/* 同時並發連接數 */);
	if(r == -1){
		printf("listen socket error : %m\n");
		exit(-1);
	}
	printf("listen socket success....\n");

	//4.receive connect
	cfd = accept(sfd,0,0);
	if(cfd == -1){
		printf("receive connect error : %m\n");
		exit(-1);
	}
	printf("start receive file....\n");

	//5.receive filename
	r = recv(cfd,&len,sizeof(len),MSG_WAITALL);
	if(r == -1){
		printf("receive filename len error : %m\n");
		exit(-1);
	}
	r = recv(cfd,filename,len,MSG_WAITALL);
	if(r == -1){
		printf("receive filename error : %m\n");
		exit(-1);
	}
	filename[len] = 0;
	printf("receive file : %s\n",filename);

	//6.create file
	ffd = open(filename,O_RDWR|O_CREAT|0666);
	if(ffd == -1){
		printf("create file error : %m\n");
		exit(-1);
	}

	//7.while receive file data
	while(1){
		r = recv(cfd,&len,sizeof(len),MSG_WAITALL);
		if(r == -1){
			printf("receive file len error : %m\n");
			exit(-1);
		}
		if(len == 0){
			break;
		}
		r = recv(cfd,buf,len,MSG_WAITALL);
		if(r == -1){
			printf("receive file content error : %m\n");
			exit(-1);
		}

		write(ffd,buf,len);
	}

	//8.close file & socket server & client
	close(ffd);
	close(cfd);
	close(sfd);
	printf("receive file complete!!!!!!!!!!!!!!!\n");

	return 0;
}

