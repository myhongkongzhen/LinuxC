/*
 * =====================================================================================
 *
 *       Filename:  6-04singaldeal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 18时34分46秒
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
#include <signal.h>

void handle(int s){
	printf("signal!!!!!\n");
}

int main(){

	signal(SIGINT,handle);

	while(1){
		printf("process executing...(%d)\n",getpid());
		sleep(1);
	}
	return 0;
}

