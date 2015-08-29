/*
 * =====================================================================================
 *
 *       Filename:  10-06qq.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月25日 10时08分38秒
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
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int sfd;
int* fds;
int idx = 0;

struct sockaddr_in dr;
int r;

int main(){

	fds = mmap(0,4*100,PROT_READ|PROT_WRITE,
			MAP_ANONYMOUS|MAP_SHARED,0,0);
	bzero(fds,sizeof(fds));

	//1.create server socket
	sfd = socket(AF_INET,SOCK_STREAM,0);	
	if(sfd == -1){
		printf("create socket : %m\n");
		exit(-1);
	}
	printf("create socket success.....\n");

	//2.bind address
	dr.sin_family = AF_INET;
	dr.sin_port = htons(6688);
	dr.sin_addr.s_addr = inet_addr("192.168.137.3");
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

	//4.while receive client connect 
	while(1){
		fds[idx] = accept(sfd,0,0);
		if(fds[idx] == -1){
			break;
		}
		printf("has client connect : %d\n",fds[idx]);

		//5.create child process
		if(fork()){
			idx++;
			continue;
		}else{
			//6.child process task: 
			//receive client data & send to all
			char buf[256];
			while(1){
				r = recv(fds[idx],buf,255,0);
				if(r == 0){
					printf("Has client exit!!!!!!!!\n");
					close(fds[idx]);
					fds[idx] = 0;
					break;
				}
				if(r == -1){
					printf("internet faild!!!!\n");
					close(fds[idx]);
					fds[idx] = 0;
					break;
				}
				buf[r] = 0;
				printf("from client data (%d): %s\n",fds[idx],buf);
				int i;
				for(i = 0 ;i < 100 ; i++){
					if(fds[i] > 0){
						send(fds[i],buf,r,0);
					}
				}
			}
			exit(0);
		}

	}

	close(sfd);

	return 0;
}

