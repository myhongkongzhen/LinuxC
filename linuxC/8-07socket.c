/*
 * =====================================================================================
 *
 *       Filename:  8-05socket.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 11时51分32秒
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
#include <fcntl.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){

	int fd;
	int r;
	char buf[300];

	printf("pid : %d,fd : %d\n",getpid(),fd);

	//create socket
	fd = socket(AF_INET/* AF_UNIX,PF_FILE,AF_UNIX... */,
			SOCK_DGRAM/* SOCK_STREAM */,0);	
	if(fd == -1){
		printf("socket create error:%m\n");
		exit(-1);
	}
	printf("socket create success....\n");

	//create local file address
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999); 
	addr.sin_addr.s_addr = inet_addr("192.168.137.3");

	//bind address to socket
	r = bind(fd,(struct sockaddr*)&addr,sizeof(addr));	
	if(r == -1){
		printf("socket bind error:%m\n");
		exit(-1);
	}
	printf("socket bind success....\n");

	//get data
	while(1){	
		bzero(buf,sizeof(buf));	
		/* 
		 * r = 0 
		 * */
		r = read(fd,buf,sizeof(buf));
		buf[r] = 0;
		printf("get data : %s\n",buf);
	}

	//close socket and delete socket file
	close(fd);

	return 0;
}

