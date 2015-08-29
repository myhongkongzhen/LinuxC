/*
 * =====================================================================================
 *
 *       Filename:  1-12memerr.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 11时14分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int errno;

int main(){
	int* p = (int*)sbrk(10000000000*4);
	if(p == (void*)-1){
		printf("error!\n");
		printf("-----------------\n");
		printf("Memory:%m\n");
		printf("-----------------\n");
		perror("error");
		printf("-----------------\n");
		printf("::%s\n",strerror(errno));
	}
	return 0;
}

