/*
 * =====================================================================================
 *
 *       Filename:  11-upd.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 19时56分37秒
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

	/* 	int r = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	 * 	if(fd == -1){
	 * 		printf("connect socket : %m\n");
	 * 		exit(-1);
	 * 	}
	 *	printf("connect socket success.....\n");
	 */

	char buf[1024];
	int r;
	while(1){
		r = read(0,buf,sizeof(buf)-2);
		if(fd <= -1){
			break;
		}

		buf[r] = '\0';
		//scanf("%s",buf);
		//write(fd,buf,strlen(buf));	
		sendto(fd,buf,r,0,
				(struct sockaddr*)&addr,sizeof(addr));
		sleep(1);
	}
	close(fd);

	return 0;
}

