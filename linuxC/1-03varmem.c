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

int add(int a,int b){
	return a+b;
}

//auto是自動變量，為臨時變量，在全局區域，
//不能添加auto關鍵字,否則段錯誤
//auto int a1 = 1;
int a1 = 1;
static int a2 = 2;
const static int a3 = 3;

int main(){
	int b1 = 4;
	static int b2 = 5;
	const static int b3 = 6;

	int* p1 = (int*)malloc(sizeof(int));
	printf("a1:%p\n",&a1);
	printf("a2:%p\n",&a2);
	printf("a3:%p\n",&a3);
	printf("b1:%p\n",&b1);
	printf("b2:%p\n",&b2);
	printf("b3:%p\n",&b3);
	printf("p1:%p\n",p1);
	printf("main:%p\n",main);
	printf("add:%p\n",add);
	printf("%d\n",getpid());

	while(1);

	return 0;
}

