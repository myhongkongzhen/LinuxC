/*
 * =====================================================================================
 *
 *       Filename:  10-01tcpserver.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 18时55分50秒
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
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

	int serverfd;
	int cfd;
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;
	socklen_t len;
	int r;

	//1.socket
	serverfd = socket(AF_INET,SOCK_STREAM,
			/* getprotobyname("tcp") */0);	
	if(serverfd == -1){
		printf("socket create error:%m\n");
		exit(-1);
	}

	//2.bind
	saddr.sin_family = AF_INET;	
	saddr.sin_port = htons(8888);
	inet_aton("192.168.137.3",&saddr.sin_addr);
	r = bind(serverfd,(struct sockaddr*)&saddr,sizeof(saddr));
	if(r == -1){
		printf("socket bind error:%m\n");
		exit(-1);
	}
	printf("socket address bind success...\n");

	//3.listen
	r = listen(serverfd,10);		
	if(r == -1){
		printf("socket listen error:%m\n");
		exit(-1);
	}
	printf("socket server listen success....\n");

	//4.accept
	while(1){
		len = sizeof(caddr);
		cfd = accept(serverfd,(struct sockaddr*)&caddr,&len);
		printf("connect:%d,ip:%s:%u\n",
				cfd,inet_ntoa(caddr.sin_addr),
				ntohs(caddr.sin_port));
	}

	return 0;
}

