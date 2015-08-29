/*
 * =====================================================================================
 *
 *       Filename:  4-01lseek.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月20日 12时13分48秒
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
#include <unistd.h>
#include <sys/types.h>

int main(){
	int fd;
	float score;
	int r;
	int i = 0;
	//char buf[getpagesize()];

	//fd = open("stu.dat",O_RDONLY);
	fd = open("stu.dat",O_RDWR);
	if(fd == -1){
		printf("open error:%m\n");
		exit(-1);
	}

	/* 	//定位	
	 * 	for(i = 0;i < 2; i ++){
	 * 		//每條記錄的開始的絕對位置
	 * 		r = lseek(fd,i*28,SEEK_SET);	
	 * 		//每條記錄的相對位置
	 * 		r = lseek(fd,24,SEEK_CUR);
	 * 		//r = lseek(fd,i*28+24,SEEK_SET);
	 * 		//讀取
	 * 		r = read(fd,&score,sizeof(float));	
	 * 		//打印輸出
	 * 		printf("%.2f\n",score);	
	 * 	}	
	 */

	/* 	r = lseek(fd,-200,SEEK_SET);
	 * 	//	r = lseek(fd,2000,SEEK_SET);
	 * 	printf("~~%d\n",r);
	 * 	//	write(fd,"Hello",sizeof("Hello"));
	 */

	for(i = 0 ; i < 2 ; i ++){
		pread(fd,&score,sizeof(float),i*28+24);
		printf("%.2f\n",score);
		read(fd,&score,sizeof(float));
		printf("%.2f\n",score);
	}

	close(fd);
	return 0;
}

