/*
 * =====================================================================================
 *
 *       Filename:  5-04system.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 17时31分13秒
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
#include <sys/wait.h>
#include <sys/types.h>

int main(){

	char buf[1024];
	FILE* f = popen("ls -l","r");

	int fd = fileno(f);
	int r;

	printf("======================\n");
	while((r = read(fd,buf,1024))>0){
		buf[r] = 0;
		printf("::%s\n",buf);
	}
	printf("======================\n");

	close(fd);
	fclose(f);
	return 0;
}

