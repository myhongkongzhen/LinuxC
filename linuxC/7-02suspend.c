/*
 * =====================================================================================
 *
 *       Filename:  7-01sigmask.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 23时41分16秒
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
#include <unistd.h>

void handle(int s){
	printf("signal ...\n");
}

int main(){

	sigset_t sigs;
	sigemptyset(&sigs);

	sigaddset(&sigs,2);

	signal(SIGINT,handle);

	sigsuspend(&sigs);
	//pause();

	printf("over!\n");

	return 0;
}

