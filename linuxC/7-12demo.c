/*
 * =====================================================================================
 *
 *       Filename:  7-12demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 04时30分51秒
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

	int fd[2];

	pipe(fd);

	if(fork()){
		//parent,write
		close(fd[0]);
		while(1){
			write(fd[1],"hello",5);
			sleep(1);
		}
	}else{
		//child,read
		char buf[20];
		int r;
		close(fd[1]);
		while(1){
			r = read(fd[0],buf,20);
			buf[r] = 0;
			printf("%s\n",buf);
		}
	}

	return 0;
}


