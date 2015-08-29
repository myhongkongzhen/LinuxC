/*
 * =====================================================================================
 *
 *       Filename:  9-07udp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 15时48分00秒
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

int main(){

	int fd;
	struct sockaddr_in ad;
	char buf[102];
	struct sockaddr_in ad_snd;
	socklen_t len;
	int r;

	fd = socket(AF_INET,SOCK_DGRAM,17);
	if(fd == -1){
		printf("socket : %m\n");
		exit(-1);
	}
	printf("create socket success....\n");

	ad.sin_family = AF_INET;
	ad.sin_port = htons(8888);
	inet_aton("192.168.137.3",&ad.sin_addr);
	r = bind(fd,(struct sockaddr*)&ad,sizeof(ad));
	if(r == -1){
		printf("socket bind : %m\n");
		exit(-1);
	}
	printf("socket bind success....\n");

	while(1){
		len = sizeof(ad_snd);
		r = recvfrom(fd,buf,sizeof(buf)-1,0,
				(struct sockaddr*)&ad_snd,&len);
		if(r > 0){
			buf[r] = 0;
			printf("send:%s,port:%hu,data : %s\n",
					inet_ntoa(ad_snd.sin_addr),
					ntohs(ad_snd.sin_port),
					buf);

			sendto(fd,"Hello!",strlen("Hello!"),0,
					(struct sockaddr*)&ad_snd,
					sizeof(ad_snd));
		}
		if(r == 0){
			printf("send close.....\n");
			close(fd);
			break;
		}
		if(r == -1){
			printf("socket connect error....\n");
			close(fd);
			break;
		}
	}

	close(fd);

	return 0;
}

