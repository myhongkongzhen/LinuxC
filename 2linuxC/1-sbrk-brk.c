/*
 * =====================================================================================
 *
 *       Filename:  1-sbrk-brk.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月31日 18时56分04秒
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

int isprimer(int a){
	int j;
	for(j = 2 ; j < a; j ++){
		if(a % j == 0){
			return 1;
		}	
	}
	return 0;
}

int main(){

	int* p=sbrk(0);
	int i;
	int r = 0;
	int* q = p;

	for(i = 2 ; i < 100 ; i ++){
		r = isprimer(i);
		if(r == 0){
			brk(q+1);
			*q = i;
			q = sbrk(0);
		}
	}

	i = 0;
	q = p;
	while(q != sbrk(0)){
		printf("%d\n",*q++);
	}

	brk(p);

	return 0;

}


