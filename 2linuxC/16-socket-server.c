/*
 * =====================================================================================
 *
 *       Filename:  16-socket-server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 18时07分22秒
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
#include <fcntl.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

void handle(int s){
	signal(SIGCHLD,handle);
	pid_t pid = wait(NULL);
	printf("clinet : %d closed.....\n",pid);
}

int main(){

	signal(SIGCHLD,handle);
	int ss = socket(AF_INET,SOCK_STREAM,0);
	if(ss == -1){
		printf("socket create : %m\n");
		exit(-1);
	}
	printf("create socket success......\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8686);
	//inet_aton("192.168.137.3",&addr.sin_addr);
	addr.sin_addr.s_addr = 0;	

	int r = bind(ss,(struct sockaddr*)&addr,sizeof(addr));
	if(r == -1){
		printf("socket bind : %m\n");
		close(ss);
		return -1;
	}
	printf("bind socket success......\n");

	r = listen(ss,20);//同時監聽20路客戶端
	if(r == -1){
		printf("socket listen: %m\n");
		close(ss);
		return -1;
	}
	printf("listen socket success......\n");

	struct sockaddr_in caddr;
	socklen_t len;
	while(1){
		len = sizeof(caddr);
		int cs = accept(ss,(struct sockaddr*)&caddr,&len);
		if(cs == -1){
			printf("socket accept: %m\n");
			continue;
		}
		if(fork()){
			//各自關閉不要的，留下需要的
			close(cs);
			continue;
		}

		//各自關閉不要的，留下需要的
		close(ss);

		char buf[2048];
		for(;;){
			/* 		char ip[100];
			 * 		inet_ntop(AF_INET,
			 * 				&caddr.sin_addr.s_addr,
			 * 				ip,sizeof(ip));
			 *		 printf("%s,到此一遊！\n",ip);
			 */
			char* ip2 = inet_ntoa(caddr.sin_addr);
			printf("%s,到此一遊!!!!！\n",ip2);

			//write(cs,ip2, strlen(ip2));
			r = recv(cs,buf,sizeof(buf),0);	
			if(r <= 0){
				printf("client brokn!\n");
				break;
			}
			if(r > 0){
				buf[r] = 0;
				printf("===%s\n",buf);
			}

		}

		close(cs);
		exit(0);

	}

	close(ss);

	return 0;
}


