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
#include <linux/un.h>

int main(){

	int fd;
	struct sockaddr_un addr = {0};
	int r;
	char buf[300];

	printf("pid : %d,fd : %d\n",getpid(),fd);

	//create create 
	fd = socket(AF_UNIX,SOCK_DGRAM,0);
	if(fd == -1){
		printf("create socket error:%m\n");
		exit(-1);
	}

	//connect address
	addr.sun_family = AF_UNIX;	
	memcpy(addr.sun_path,"my.sock",strlen("my.sock"));
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

