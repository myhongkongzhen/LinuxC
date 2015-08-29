/*
 * =====================================================================================
 *
 *       Filename:  6-03getlock.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 17时59分44秒
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

	int fd;
	struct flock lk = {0};
	int r;

	fd = open("stu.dat",O_RDWR);
	if(fd == -1){
		printf("open error:%m\n");
		exit(-1);
	}

	r = fcntl(fd,F_GETLK,&lk);
	if(r == 0){
		printf("得到鎖成功\n");
	}

	if(lk.l_type == F_WRLCK){
		printf("寫鎖\n");
	}
	printf("start : %d\tlen : %d\n",lk.l_start,lk.l_len);
	printf("PID : %d\n",lk.l_pid);

	close(fd);
	return 0;
}

