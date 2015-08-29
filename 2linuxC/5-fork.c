/*
 * =====================================================================================
 *
 *       Filename:  5-fork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 10时15分47秒
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
#include <fcntl.h>

int main(){

	int fd = open("test.txt",O_RDWR);
	int r;
	char buf[1024];

	/* 	if(fork()){
	 * 		r = read(fd,buf,1020);
	 * 		buf[r] = 0;
	 * 		printf("parent:::%s\n",buf);
	 * 		while(1);
	 * 		close(fd);
	 * 	}else{
	 * 		r = read(fd,buf,1020);
	 * 		buf[r] = 0;
	 * 		printf("child:::%s\n",buf);
	 * 		close(fd);
	 * 		while(1);
	 * 	}
	 */

	if(fork()){
		write(fd,"hello\n",6);
		close(fd);
	}else{
		write(fd,"world\n",6);
		close(fd);
	}

	return 0;
}

