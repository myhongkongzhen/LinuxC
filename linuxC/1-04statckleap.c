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
	int a1 = 10;
	int a2 = 20;
	int a3 = 30;

	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int));
	int* p4 = (int*)malloc(4);

	printf("a1 = %p\n",&a1);
	printf("a2 = %p\n",&a2);
	printf("a3 = %p\n",&a3);
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);
	printf("p4 = %p\n",p4);

	printf("%d\n",getpid());

	while(1);

	return 0;
}

