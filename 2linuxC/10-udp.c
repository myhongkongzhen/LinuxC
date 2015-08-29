/*
 * =====================================================================================
 *
 *       Filename:  10-udp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 19时22分08秒
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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){

	int fd = socket(AF_INET,SOCK_DGRAM,0);
	if(fd == -1){
		printf("socket : %m\n");
		exit(-1);
	}
	printf("create socket success.....\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8686);
	inet_aton("192.168.137.3",&addr.sin_addr);

	int r = bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r == -1){
		printf("bind socket : %m");
		exit(-1);
	}
	printf("bind socket success.....\n");

	char buf[1024];
	struct sockaddr_in ad_snd;
	int len;
	while(1){
		len = sizeof(ad_snd);
		r = recvfrom(fd,buf,sizeof(buf),0,
				(struct sockaddr*)&ad_snd,
				&len);	
		if(r == -1){
			printf("socket net faild.....\n");
			break;
		}
		if(r == 0){
			printf("sender closed....\n");
			break;
		}
		if(r > 0){
			buf[r] = '\0';
			printf("%s::%s\n",
					inet_ntoa(ad_snd.sin_addr),buf);
		}
	}
	close(fd);

	return 0;
}


