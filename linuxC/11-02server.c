/*
 * =====================================================================================
 *
 *       Filename:  11-02server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月25日 19时06分15秒
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
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){

	int sfd;
	int fdall[100];
	int count;
	int r;
	struct sockaddr_in dr;
	fd_set fds;
	int maxfd;
	int i,j;
	char buf[1024];

	//1.create socket
	sfd = socket(AF_INET,SOCK_STREAM,6);
	if(sfd == -1){
		printf("create socket : %m\n");
		exit(-1);
	}
	printf("create socket success.....\n");

	//2.bind address port
	dr.sin_family = AF_INET;
	dr.sin_port = htons(6688);
	//	dr.sin_addr.s_addr = inet_atos("192.168.137.3");
	inet_aton("192.168.137.3",&dr.sin_addr);
	r = bind(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r == -1){
		printf("bind socket : %m\n");
		exit(-1);
	}
	printf("bind socket success.....\n");

	//3.listen
	r = listen(sfd,10);
	if(r == -1){
		printf("listen socket : %m\n");
		exit(-1);
	}
	printf("listen socket success.....\n");
	count = 0;
	maxfd = 0;
	FD_ZERO(&fds);
	for(i = 0 ; i < 100 ; i ++){
		fdall[i] = -1;
	}

	//4.construct listen fd set :
	//	server fd set and client fd set
	while(1){
		//	4.1 clean
		FD_ZERO(&fds);
		maxfd = 0;
		//	4.2 add server fd
		FD_SET(sfd,&fds);	
		maxfd = (maxfd >= sfd ? maxfd : sfd);
		//	4.3 add client fd
		for(i = 0 ; i < count ; i ++){
			if(fdall[i] != -1){
				FD_SET(fdall[i],&fds);
				maxfd = (maxfd >= fdall[i] ? maxfd : fdall[i]);
			}
		}

		//5.use select control fd set;
		r = select(maxfd+1,&fds,0,0,0);
		if(r == -1){
			printf("listen socket : %m\n");
			break;
		}

		//6.1.has client connect [server fd set]
		if(FD_ISSET(sfd,&fds)){
			fdall[count++] = accept(sfd,0,0);
			printf("has client connect ....\n");
		}	

		//6.2.has client send data [client fd set]
		for(i = 0 ; i < count ; i ++){
			if(fdall[i] != -1 && FD_ISSET(fdall[i],&fds)){
				r = recv(fdall[i],buf,1023,0);				
				if(r == 0){
					printf("has client exit......\n");
					close(fdall[i]);
					fdall[i] = -1;
				}
				if(r == -1){
					printf("has internet fail....(%m)\n");
					close(fdall[i]);
					fdall[i] = -1;
				}
				if(r > 0){
					for(j = 0 ; j < count ; j ++){
						if(fdall[j] != -1){
							send(fdall[j],buf,r,0);
						}
					}
				}
			}
		}

	}

	return 0;
}

