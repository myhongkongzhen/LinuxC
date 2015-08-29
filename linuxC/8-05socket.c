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
	int r;
	char buf[300];

	printf("pid : %d,fd : %d\n",getpid(),fd);

	//create socket
	fd = socket(AF_UNIX/* AF_UNIX,PF_FILE,AF_INET... */,
			SOCK_DGRAM/* SOCK_STREAM */,0);	
	if(fd == -1){
		printf("socket create error:%m\n");
		exit(-1);
	}
	printf("socket create success....\n");

	//create local file address
	struct sockaddr_un addr = {0};
	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path,"my.sock",strlen("my.sock"));

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

