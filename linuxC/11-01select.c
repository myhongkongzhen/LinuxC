/*
 * =====================================================================================
 *
 *       Filename:  11-01select.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月25日 18时56分05秒
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
#include <signal.h>
#include <sys/select.h>
#include <fcntl.h>

int main(){

	fd_set fds;
	int r;
	char buf[100];
	while(1){
		FD_ZERO(&fds);
		FD_SET(0,&fds);
		r = select(1,&fds,0,0,NULL); 
		printf("has data input.......\n");
		r = read(0,buf,99);
	}

	return 0;
}

