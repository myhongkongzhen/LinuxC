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
int i;

void end(int s){
	close(fd);
	unlink("my.pipe");
	exit(-1);
}

int main(){

	signal(SIGINT,end);
	mkfifo("my.pipe",0666);
	fd = open("my.pipe",O_RDWR);
	shutdown(fd,SHUT_RD);
	while(1){
		sleep(1);
		write(fd,&i,4);
		i++;
	}
	return 0;
}

