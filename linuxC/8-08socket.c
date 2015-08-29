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
	struct sockaddr_in addr = {0};
	int r;
	char buf[300];

	printf("pid : %d,fd : %d\n",getpid(),fd);

	//create create 
	fd = socket(AF_INET,SOCK_DGRAM,0);
	if(fd == -1){
		printf("create socket error:%m\n");
		exit(-1);
	}

	//connect address
	addr.sin_family = AF_INET;	
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = inet_addr("192.168.137.3");
	r = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(fd == -1){
		printf("connect socket error:%m\n");
		exit(-1);
	}

	//send data
	write(fd,"Hi,mizu!!!!!!",strlen("Hi,mizu!!!!!!"));
	//close
	close(fd);	

	return 0;
}

