/*
 * =====================================================================================
 *
 *       Filename:  head.c
 *
 *    Description:  申請堆區空間
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 11时19分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main(){
	double* d = (double*)malloc(sizeof(double));
	int* a = (int*)calloc(5,sizeof(int));
	printf("%p ,%p\n",d,a);
	*d = 34.45;
	int i;
	for(i = 0 ;  i< 5 ; i++){
		a[i] = i+10;	
	}
	printf("%g\n",*d);
	for(i = 0 ;  i< 5 ; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	free(d);
	a = realloc(a,sizeof(int)*10);
	if(a == NULL){
		printf("申請空間失敗\n");
		return 1;
	}
	for(i = 0 ;  i< 10 ; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	a = realloc(a,0);
	printf("----%p\n",a);
	for(i = 0 ;  i<10 ; i++)
		free(a+i);
	return 0;
}



