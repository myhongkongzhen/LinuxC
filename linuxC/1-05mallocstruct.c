/*
 * =====================================================================================
 *
 *       Filename:  1-03varmem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 06时20分40秒
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

int main(){

	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	//int* p3 = (int*)malloc(sizeof(int));

	*p1 = 1;
	*(p1+1) = 2;
	*(p1+2) = 3;
	*(p1+3) = 4;
	*(p1+4) = 5;
	*(p1+5) = 6;
	*(p1+6) = 7;
	*(p1+7) = 8;
	*(p1+8) = 9;

	free(p1);
	printf("p2 = %d\n",*p2);

	//printf("%d\n",getpid());
	//while(1);

	return 0;
}

