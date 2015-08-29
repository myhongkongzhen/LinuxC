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
	int ffd;
	int r;
	int size;
	int len;
	char buf[128];//default 8K
	struct sockaddr_in dr;
	char filename[] = "Makefile_";

	//1.create socket
	sfd = socket(AF_INET,SOCK_STREAM,0/* 6:TCP */);
	if(sfd == -1){
		printf("create socket error:%m\n");
		exit(-1);
	}
	printf("create socket success.....\n");

	//2.connect server
	dr.sin_family = AF_INET;
	dr.sin_port = htons(8888);
	inet_aton("192.168.137.3",&dr.sin_addr);
	r = connect(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r == -1){
		printf("connect socket error:%m\n");
		exit(-1);
	}
	printf("connect socket success.....\n");

	//3.open file
	ffd = open(filename,O_RDONLY /* ,0 */);
	if(ffd == -1){
		printf("open file error:%m\n");
		exit(-1);
	}
	printf("open file success.....\n");

	//4.send filename
	len = strlen(filename);
	r = send(sfd,&len,sizeof(len),0);
	if(r == -1){
		printf("send filename len error:%m\n");
		exit(-1);
	}
	r = send(sfd,filename,len,0);
	if(r == -1){
		printf("send filename error:%m\n");
		exit(-1);
	}
	printf("send filename success.....\n");

	//5.while send file data
	while(1){
		size = read(ffd,buf,128);
		if(size == -1 ){
			printf("read file error:%m\n");
			break;
		}
		if(size == 0 ){
			break;
		}
		if(size > 0){
			r = send(sfd,&size,sizeof(r),0);
			if(r == -1 ){
				printf("send filesize error:%m\n");
				break;
			}
			send(sfd,buf,size,0);
			if(r == -1 ){
				printf("send file error:%m\n");
				break;
			}
		}
	}

	//6.file eof send zeor packet
	size = 0;
	r = send(sfd,&size,sizeof(size),0);

	//7.close file and socket
	close(ffd);
	close(sfd);
	printf("file send success!!!!!!!!!!!!!!!!\n");

	return 0;
}

