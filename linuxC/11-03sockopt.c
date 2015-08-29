/*
 * =====================================================================================
 *
 *       Filename:  11-03sockopt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月26日 08时37分06秒
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
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

	int fd;
	int type;
	int len;
	len = sizeof(type);

	fd = socket(AF_INET,SOCK_DGRAM,0);


	getsockopt(fd,SOL_SOCKET,SO_TYPE,&type,&len);
	//	printf("%u:%u\n",SOCK_STREAM,type);
	//	getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&type,&len);
	printf("%u:%u\n",SOCK_DGRAM,type);

	if(type & SOCK_STREAM){
		printf("stream......\n");
	}

	if(type & SOCK_DGRAM){
		printf("dgram......\n");
	}

	return 0;
}

