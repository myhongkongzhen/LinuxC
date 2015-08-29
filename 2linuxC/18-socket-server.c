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

int main(){

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
	char buf[2048];
	len = sizeof(caddr);
	int cs = accept(ss,(struct sockaddr*)&caddr,&len);
	if(cs == -1){
		printf("socket accept: %m\n");
		close(ss);
		return 0;
	}
	while(1){

		char* ip2 = inet_ntoa(caddr.sin_addr);
		printf("%d===%s:,到此一遊!!!!！\n",cs,ip2,
				ntohs(caddr.sin_port));

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
	close(ss);

	return 0;
}


