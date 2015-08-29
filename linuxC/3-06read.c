/*
 * =====================================================================================
 *
 *       Filename:  3-05open.c
 *
 *    Description:  打開文件讀取數據  
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
#include <string.h>

int main(){

	char name[20];
	short age;
	float score;
	char sex;

	int fd;
	int r;

	fd = open("test.dat",O_RDONLY);//只對創建時有效
	if(fd == -1){
		printf("open file error:%m\n");
		exit(-1);
	}

	while(1){
		r = read(fd,name,sizeof(name));	
		if(r == 0){
			break;
		}
		r = read(fd,&age,sizeof age);
		r = read(fd,&score,sizeof(score));
		r = read(fd,&sex,sizeof(char));
		printf("%s\t%4hd\t%.2f\t%c\n",name,age,score,sex);
	}

	close(fd);
	return 0;
}

