/*
 * =====================================================================================
 *
 *       Filename:  4-04map_write.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月20日 20时23分15秒
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
#include <string.h>
#include <sys/mman.h>

typedef struct stu{
	char name[20];
	int age;
	float score;
}stu;

int main(){
	int fd;
	struct stat s;//文件在虛擬內存中影射首地址
	int size;//文件大小
	int count;//文件條數
	stu *st;
	int i;
	//memset(&record,0,sizeof(stu));//初始化為0

	//打開文件
	fd = open("newstu.dat",O_RDWR|O_CREAT|O_EXCL,0666);	
	if(fd == -1){
		fd = open("newstu.dat",O_RDWR);
		if(fd == -1){
			printf("open error:%m\n");
			exit(-1);
		}
	}

	fstat(fd,&s);
	size = s.st_size;
	count = size/sizeof(stu);

	//影射到一個虛擬地址
	st = mmap(0,size+sizeof(stu),
			PROT_READ|PROT_WRITE,
			MAP_SHARED,fd,0);	

	//文件大小改變，只要在munmap之前調用都有效
	//	ftruncate(fd,size+sizeof(stu));

	//把數據寫入虛擬地址
	//,s[count].name,sizeof(s[count].name);
	//	printf("input name : ");	
	//	scanf("%s",st[count].name);	
	//	printf("input age: ");	
	//	scanf("%d",&(st[count].age));	
	//	printf("input score: ");	
	//	scanf("%f",&(st[count].score));	

	for( i = 0 ; i < count ; i ++){
		printf("%s\t%d\t%.2f\n",
				st[i].name,st[i].age,st[i].score);
	}

	//卸載虛擬地址
	munmap(st,sizeof(stu)+size);	
	//關閉文件
	close(fd);

	return 0;
}

