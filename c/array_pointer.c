/*
 * =====================================================================================
 *
 *       Filename:  array_pointer.c
 *
 *    Description:  指向數組的指針
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 07时30分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(){
	int* p[5];//p不是個指針	
	int* q(double);//q也不是個指針
	int(*r)[5]; //r才是指針
	/* 	int m;
	 * 	int* n;
	 * 	n = &m;
	 */
	int x[5] = {11,22,33,44,55};
	int y[6] = {12,23,34,45,56,67};
	int z[3][5] = {{1,2,3},{4,5},{7,89,0,2,1}};
	//x本身表示x[0]的地址，&x[0],int* 類型
	//而&x表示這個數組的地址,int(*)[5]類型
	r = &x;//指向數組的指針，獲取的是數組的地址
	int i = 0;
	for ( ; i < 5;i++ ) {
		printf("%d ",(*r)[i]);
	}
	printf("\n");
	r = z; //這是一個合法的賦值，因為z表示的是z[0]的地址
	int j;
	for(i = 0 ; i < 3 ; i ++,printf("\n")){
		for(j = 0 ; j < 5 ; j ++){
			printf("%d ",r[i][j]);
		}
	}
	return 0;
}




