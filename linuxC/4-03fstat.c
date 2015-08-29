/*
 * =====================================================================================
 *
 *       Filename:  4-03fstat.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月20日 20时12分22秒
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
#include <sys/stat.h>

typedef struct stat stt;

int main(){
	int fd;
	stt st;

	fd  = open("stu.dat",O_RDONLY);
	if(fd == -1){
		printf("open error:%m\n");
		exit(-1);
	}

	fstat(fd,&st);
	printf("%d,%o\n",st.st_size,st.st_mode);

	close(fd);
	return 0;
}

