/*
 * =====================================================================================
 *
 *       Filename:  3-05open.c
 *
 *    Description:  
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

	int fd = open("test.dat",
			O_RDWR|O_CREAT|O_EXCL,
			00666);//只對創建時有效
	if(fd == -1){
		printf("open file error:%m\n");
		exit(-1);
	}

	//one
	memcpy(name,"mizu",strlen("mizu")+1);
	age = 30;
	score = 99.99;
	sex = 'F';

	write(fd,name,sizeof(name));
	write(fd,&age,sizeof age);
	write(fd,&score,sizeof(float));
	write(fd,&sex,sizeof(char));

	//two
	memcpy(name,"tani",strlen("tani")+1);
	age = 20;
	score = 98.99;
	sex = 'M';

	write(fd,name,sizeof(name));
	write(fd,&age,sizeof age);
	write(fd,&score,sizeof(float));
	write(fd,&sex,sizeof(char));

	//three
	memcpy(name,"純",strlen("純")+1);
	age = 330;
	score = 100.0;
	sex = 'M';

	write(fd,name,sizeof(name));
	write(fd,&age,sizeof age);
	write(fd,&score,sizeof(float));
	write(fd,&sex,sizeof(char));

	close(fd);
	return 0;
}

