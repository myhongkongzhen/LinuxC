/*
 * =====================================================================================
 *
 *       Filename:  6-02setlock.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 17时58分55秒
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

int main(){
	int r;
	int fd;
	struct flock lk;

	fd = open("stu.dat",O_RDWR);
	if(fd == -1){
		printf("open error:%m\n");
		exit(-1);
	}

	//描述鎖
	lk.l_type = F_WRLCK;
	lk.l_whence = SEEK_SET;
	lk.l_start = 5;
	lk.l_len = 10;

	//加鎖
	r = fcntl(fd,F_SETLK,&lk);
	if(r == 0){
		printf("加鎖成功\n");
	}else{
		printf("加鎖失敗\n");
	}

	while(1);
	close(fd);
	return 0;
};

