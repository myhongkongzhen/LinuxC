/*
 * =====================================================================================
 *
 *       Filename:  19-qq-client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 21时58分04秒
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
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void handle(int status){
	signal(SIGCHLD,handle);
	signal(SIGINT,handle);
	if(status == SIGCHLD){
		pid_t pid = wait(NULL);
		printf("client : %d exit.....\n",pid);
	}else{
		printf("child process server exit......\n");
		exit(0);
	}
}

int main(){

	signal(SIGINT,handle);
	signal(SIGCHLD,handle);
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1){
		printf("socket create : %m\n");
		return -1;
	}
	printf("create socket success.....\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8866);
	inet_aton("192.168.137.3",&addr.sin_addr);

	int r = bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r == -1){
		printf("socket bind: %m\n");
		return -1;
	}
	printf("bind socket success.....\n");

	r = listen(fd,10);
	if(r == -1){
		printf("socket listen: %m\n");
		return -1;
	}
	printf("listen socket success.....\n");

	struct sockaddr_in caddr;
	int cfd;
	char buf[256];
	while(1){
		socklen_t len = sizeof(caddr);
		cfd = accept(fd,(struct sockaddr*)&caddr, &len);
		if(r == -1){
			continue;
		}

		char* ip = inet_ntoa(caddr.sin_addr);
		int port = ntohs(caddr.sin_port);
		printf("%s:%u connected.....\n",ip,port);

		if(fork()){
			close(cfd);
			continue;
		}

		close(fd);
		while(1){
			r = recv(cfd,buf,255,0);
			if(r == 0){
				printf("%s:%u exit.....\n",ip,port);
				exit(-1);
			}
			if(r == -1){
				printf("net faild....\n");
				exit(-1);
			}
			buf[r] = 0;
			printf(":::::::%s\n",buf);
			write(cfd,buf,255);
		}
	}

	close(fd);
	return 0;
}


