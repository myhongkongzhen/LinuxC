/*
 * =====================================================================================
 *
 *       Filename:  7-13demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 04时48分48秒
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
#include <signal.h>
#include <string.h>
#include <sched.h>

int idx = 0 ;
int fddata = 0;
void handle(int s){
	int status;
	if(s == SIGCHLD){
		wait(&status);
		if(++idx == 2){
			close(fddata);
			printf("task complete\n");
			exit(-1);
		}
	}
}

int isprimer(int ta){
	int i = 2;
	for(; i < ta ; i ++){
		if(ta%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){

	int a = 1,b = 5000;
	int id = 1;
	int fd[2];

	signal(SIGCHLD,handle);

	pipe(fd);

	while(1){
		if(id == 1){
			a = 2;
			b = 5000;
		}else{
			a = 5001;
			b = 10000;
		}
		if(fork()){
			//parent
			id ++;
			if(id > 2){
				//創建兩個子進程之後中斷循環
				break;
			}
			continue;
		}else{
			//child:1
			int i;	
			close(fd[0]);
			for(i = a; i <= b; i ++){
				if(isprimer(i)){
					//printf("%d:%d\n",getpid(),i);
					write(fd[1],&i,sizeof(int));	
				}
				sched_yield();
			}
			printf("%d task complete..\n",getpid());
			exit(0);
		}
	}

	char buf[20];
	int r;
	close(fd[1]);
	fddata = open("result.txt",O_RDWR|O_CREAT,0666);
	while(1){
		read(fd[0],&r,sizeof(int));
		sprintf(buf,"%d\n",r);
		write(fddata,buf,strlen(buf));
	}

	return 0;
}

