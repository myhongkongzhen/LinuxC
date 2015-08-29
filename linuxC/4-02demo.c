/*
 * =====================================================================================
 *
 *       Filename:  4-02demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月20日 19时34分41秒
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
#include <fcntl.h>

int a = 9999;

int main(){
	char filename[100];
	int fd;
	int data;

	//得到文件名
	sprintf(filename,"/proc/%d/mem",getpid());

	fd = open(filename,O_RDWR);
	if(fd == -1){
		printf("open file error:%m\n");
		exit(-1);
	}

	//	pread(fd,&data,4,((int)&a));
	/* 	lseek(fd,(int)&a,SEEK_SET);	
	 * 	read(fd,&data,4);
	 *	printf("%d\n",data);
	 */
	//	lseek(fd,(int)&a,SEEK_SET);	
	//	write(fd,&data,4);
	pwrite(fd,&data,4,(int)&a);
	printf("%d\n",a);

	close(fd);
	return 0;
}

