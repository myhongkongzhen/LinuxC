/*
 * =====================================================================================
 *
 *       Filename:  6-demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 10时27分12秒
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
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>

int* p = mmap(0,getpagesize(),PROT_READ|PROT_WRITE,
		MAP_ANONYMOUS|MAP_SHARED,0,0);

void handle(int s){
	wait(&s);
	printf("child exit.....\n");
}

int isprimer(int a){
	int i;
	for(i = 2; i < a; i ++){
		if(a % i == 0){
			return 0;
		}
	}
	return 1;
}

void primer(int a,int b){
	int i;
	int r;
	int* q = p;
	for(i = a ; i < b ; i ++){
		r = isprimer(i);	
		if(i == 1){
			brk(q+1);	
			*q = i;
			q = sbrk(0);
		}
	}
}

int main(){

	int i = 1;
	int a,b;
	while(1){
		if(i == 0){
			a = 1;
			b = 5000;
		}
		if(i == 1){
			a = 5000;
			b = 10000;
		}
		if(fork()){
			if(i++>2){
				break;
			}
			continue;
		}else{
			signal(17,handle);
			primer(5000,10000);
		}
	}

	while(1){
		int fd = open("primer.dat",
				O_RDWR|O_CREAT,0666);
		if(fd == -1){
			printf("open error:%m\n");
			exit(-1);
		}
		int* q = p;
		while(q != sbrk(0)){
			printf("%d\n",*q++);
			//write(fd,*q++,sizeof(int));
		}
		close(fd);
	}

	return 0;
}



