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
	int fd = open(filename,
			O_RDWR|O_CREAT|O_EXCL,
			0666);//只對創建時有效
	if(fd == -1){//表示文件存在,則打開
		fd = open(filename,O_RDWR|O_APPEND);	
	}
	return fd;
}

void input(stu* sturc){
	bzero(sturc,sizeof(sturc));
	printf("input no:");
	scanf("%d",&(sturc->no));
	printf("input name:");
	scanf("%s",sturc->name);
	printf("input score:");
	scanf("%f",&(sturc->score));
}

void save(int fd,stu* sturc){
	write(fd,sturc,sizeof(stu));
}

int iscontinue(){
	char c;
	printf("is continue ?\n");
	scanf(" %c",&c);
	return ((c == 'Y' || c == 'y')?1:0);
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
		input(&s);
		save(fd,&s);
		r = iscontinue();
		if(r==0){
			break;
		}
		system("clear");
	}

	close(fd);
	printf("input complete!\n");
	return 0;
}

