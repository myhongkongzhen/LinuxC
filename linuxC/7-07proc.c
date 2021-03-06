/*
 * =====================================================================================
 *
 *       Filename:  7-07proc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 02时45分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>

int main(){

	int * p;
	int fd ;
	int i;
	fd = open("tmp",O_RDWR|O_CREAT,0666);
	if(fd == -1){
		printf("error : %m\n");
		exit(-1);
	}

	ftruncate(fd,4);
	p = mmap(0,4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	i = 0;
	while(1){
		sleep(1);
		*p = i++;
	}

	close(fd);
	return 0;
}

