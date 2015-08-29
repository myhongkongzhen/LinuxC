/*
 * =====================================================================================
 *
 *       Filename:  9-demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 09时03分32秒
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
#include <fcntl.h>

int main(){

	int id = 1;
	int a,b;
	while(1){
		if(id == 1){
			a = 1;
			b = 5000;
		}else if(id == 2){
			a = 5001;
			b = 10000;
		}
		if(fork()){
			if(id++<2){
				continue;
			}
			while(1){
				printf("parent:%d\n",getpid());
				sleep(1);
			}
			exit(1);
		}else{
			while(1){
				printf("child:%d,a:%d,b:%d\n",getpid(),a,b);
				sleep(1);
			}
			exit(1);
		}
	}

	return 0;
}

