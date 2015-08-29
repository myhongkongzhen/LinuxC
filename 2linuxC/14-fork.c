/*
 * =====================================================================================
 *
 *       Filename:  14-fork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 14时06分38秒
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
	signal(SIGCHLD,handle);
	pid_t pid = wait(NULL);
	printf("---%d--wait-child----\n",pid);
}

void child(char c,int l){
	int i;
	if(fork())return;
	for(i = 0 ; i < l ; i ++){
		printf("%d::%c\n",getpid(),c);
		sleep(2);
	}
	exit(0);
}

int main(){

	signal(SIGCHLD,handle);
	child('.',7);
	child('^',13);
	int i;
	for(i = 0 ; i < 100 ; i ++){
		printf("pid:%d-$\n",getpid());
		sleep(1);
	}

	return 0;
}

