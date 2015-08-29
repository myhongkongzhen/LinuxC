/*
 * =====================================================================================
 *
 *       Filename:  11-04cast.c
 *
 *    Description:  廣播方
 *
 *        Version:  1.0
 *        Created:  2014年08月26日 08时49分35秒
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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){

	int fd;
	int opt = 1;
	struct sockaddr_in dr;
	int r;

	fd = socket(PF_INET,SOCK_DGRAM,0);
	if(fd == -1){
		printf("create socket : %m\n");
		exit(-1);
	}

	r = setsockopt(fd,SOL_SOCKET,SO_BROADCAST,
			&opt,sizeof(opt));
	if(r == -1){
		printf("set socket option: %m\n");
		exit(-1);
	}

	dr.sin_family = PF_INET;
	dr.sin_port = htons(8888);
	dr.sin_addr.s_addr = inet_addr("192.168.137.255");

	sendto(fd,"hello",5,0,
			(struct sockaddr*)&dr,sizeof(dr));
	//	if(r == -1){
	//		printf("set socket option: %m\n");
	//		exit(-1);
	//	}

	close(fd);

	return 0;
}

