/*
 * =====================================================================================
 *
 *       Filename:  6-01atexit.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 01时06分46秒
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

void fun(){
	printf("over....\n");
}

int main(){
	atexit(fun);
	printf("process!\n");
	return 0;
}

