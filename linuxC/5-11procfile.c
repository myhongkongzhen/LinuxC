/*
 * =====================================================================================
 *
 *       Filename:  5-08tasks.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 20时13分09秒
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
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(){


	if(fork()){
		int fd = open("stu.dat",O_RDWR);
		write(fd,"killer",5);
		close(fd);
	}else{
		int fd = open("stu.dat",O_RDWR);
		write(fd,"clinton",5);
		close(fd);
	}


	return 0;
}


