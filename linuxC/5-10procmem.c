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
#include <sys/mman.h>

int main(){

	int* a = sbrk(4);
	//	int* a = mmap(0,4,
	//			PROT_READ|PROT_WRITE,
	//			MAP_ANONYMOUS|MAP_PRIVATE,0,0);
	//MAP_ANONYMOUS|MAP_SHARED,0,0);
	//	int* a = (int*)malloc(sizeof(int)); 
	*a = 40;
	if(fork()){
		printf("parent:%d\n",*a);
		*a = 90;
	}else{
		printf("child:%d\n",*a);
		sleep(2);
		printf("---child:%d\n",*a);
	}

	return 0;
}


