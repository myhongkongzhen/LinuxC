/*
 * =====================================================================================
 *
 *       Filename:  15-deamon.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 11时10分51秒
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

void make_deamon();
void work();

int main(){

	make_deamon();
	return 0;
}

void work(){

	char ch = 'A';
	for(;;){
		int fd = open("deamon.dat",
				O_WRONLY|O_CREAT|O_APPEND,0666);
		if(fd != 0){
			write(fd,&ch,1);	
			close(fd);
		}
		if(ch++>'Z'){
			ch = 'A';
		}
		sleep(2);
	}
}

void make_deamon(){

	if(fork()){
		exit(0);
	}

	setsid();
	umask(0077);
	int i;
	for(i = 0 ; i < 256 ; i ++){
		close(i);
	}
	work();
}

