/*
 * =====================================================================================
 *
 *       Filename:  7-09fifo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 03时12分46秒
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
#include <sys/stat.h>
#include <sys/socket.h>
#include <signal.h>

int fd;

void end(int s){
	close(fd);
	exit(-1);
}

int main(){
	int i;
	signal(SIGINT,end);
	fd = open("my.pipe",O_RDWR);
	shutdown(fd,SHUT_WR);
	while(1){
		read(fd,&i,4);
		printf("%d\n",i);
	}
	return 0;
}

