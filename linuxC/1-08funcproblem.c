/*
 * =====================================================================================
 *
 *       Filename:  1-08funcproblem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 08时15分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int add(int a,int b){
	return a+b;
}

int add2(int* a,int* b){
	return (*a)+(*b);
}

int main(){
	//int (*fun)(int) = (int(*)(int))add;
	//typedef int(*fun)(int,int,int);
	typedef int(*fun)(int);
	fun f = (fun)add;
	//int r = f(20,5,76);
	int r = f(20);
	printf("%d\n",r);
	printf("===========================\n");

	int a = 20;
	int b = 30;
	int ab = add2(&a,&b);
	printf("%d\n",ab);

	return 0;
}


