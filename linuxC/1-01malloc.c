/*
 * =====================================================================================
 *
 *       Filename:  1-01malloc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 05时46分52秒
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

int main(){
	int *p1 = (int*)malloc(sizeof(int));
	int *p2 = (int*)malloc(sizeof(int));
	int *p3 = (int*)malloc(sizeof(int));
	int *p4 = (int*)malloc(sizeof(int));
	int *p5 = (int*)malloc(sizeof(int));
	printf("%p\n",p1);
	printf("%p\n",p2);
	printf("%p\n",p3);
	printf("%p\n",p4);
	printf("%p\n",p5);
	printf("%d\n",getpid());
	while(1);
	return 0;
}

