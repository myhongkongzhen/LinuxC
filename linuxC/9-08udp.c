/*
 * =====================================================================================
 *
 *       Filename:  9-08udp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 16时15分09秒
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
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

int main(){
	int fd;
	struct sockaddr_in ad;
	char buf[102];
	int r;

	fd = socket(AF_INET,SOCK_DGRAM,0);
	ad.sin_family = AF_INET;
	ad.sin_port = htons(8888);
	ad.sin_addr.s_addr = inet_addr("192.168.137.3");
	//	connect(fd,(struct sockaddr*)&ad,sizeof(ad));

	while(1){
		r = read(0,buf,sizeof(buf)-1);
		if(r <= 0){
			break;
		}
		buf[r] = 0;
		r =	sendto(fd,buf,r,0,
				(struct sockaddr*)&ad,sizeof(ad));
		//	r = send(fd,buf,r,0);	
		bzero(buf,sizeof(buf));
		r = recv(fd,buf,sizeof(buf),0);
		buf[r] = 0;
		printf("--->%s\n",buf);
		if(r == -1){
			break;
		}
	}

	close(fd);

	return 0;
}

