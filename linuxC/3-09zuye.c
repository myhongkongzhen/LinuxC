/*
 * =====================================================================================
 *
 *       Filename:  3-05open.c
 *
 *    Description:  結構體數據讀取  
 *
 *        Version:  1.0
 *        Created:  2014年08月20日 09时29分14秒
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
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct stu{
	int no;
	char name[20];
	float score;
}stu;

int openfile(const char* filename) {
	return open(filename,O_RDWR|O_APPEND);	
}

int main(){
	int fd;
	int r;
	stu s = {0};

	fd = openfile("stu.dat");
	if(fd == -1){
		printf("open file error:%m\n");
		exit(-1);
	}

	while(1){
		r = read(fd,&s,sizeof(stu));
		if(r == 0){
			break;
		}
		printf("%d\t%s\t%.2f\n",s.no,s.name,s.score);
	}

	close(fd);
	return 0;
}

