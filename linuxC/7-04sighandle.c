/*
 * =====================================================================================
 *
 *       Filename:  7-04sighandle.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 00时53分37秒
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
#include <signal.h>

void handle(int s){
	printf("hello start.....\n");
	sleep(20);
	printf("hello end.....\n");
}

int main(){

	signal(SIGINT,handle);

	while(1);

	return 0;
}

