/*
 * =====================================================================================
 *
 *       Filename:  7-demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 14时15分16秒
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
#include <sys/mman.h>


int isprimer(int a){
	int i;
	for(i = 2; i < a; i++){
		if(a % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int* p = mmap(0,4,PROT_READ|PROT_WRITE,MAP_SHARED,0,0);
	int id = 1;
	int a,b;
	while(1){
		if(id == 1){
			a = 1;
			b = 5000;
		}
		if(id == 2){
			a = 5000;
			b = 10000;
		}
		if(fork()){
			if(++id>2){
				int fd = open("primer.dat",
						O_RDWR|O_CREAT,0666);
				if(fd == -1){
					printf("open error:%m\n");
					exit(-1);
				}
				int* q = p;
				while(q != NULL){
					printf("%d\n",*q++);
					//write(fd,*q++,sizeof(int));
				}
				close(fd);
			}
		}else{
			int i;
			int r;
			int* q = p;
			for(i = a ; i < b ; i ++){
				r = isprimer(i);
				if(r == 1){
					*q++ = i;	
				}
			}
			printf("pid:%d task complete!\n",getpid());
			exit(0);
		}
	}
	return 0;
}

