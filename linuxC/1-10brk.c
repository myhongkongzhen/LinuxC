/*
 * =====================================================================================
 *
 *       Filename:  1-10brk.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 09时57分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <unistd.h>

int main(){
	int* p1 = (int*)sbrk(4);
	int* p2 = (int*)sbrk(200);
	int* p3 = (int*)sbrk(0);
	//-------------------釋放
	int* p4 = (int*)sbrk(-4);
	int* p5 = (int*)sbrk(-4);
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);
	printf("p4 = %p\n",p4);
	printf("p5 = %p\n",p5);
	printf("---------------\n");
	//分配一個int的空間
	//返回空間地址
	/* 	int* p = (int*)sbrk(sizeof(int));
	 * 	*p = 6666;
	 * 	printf("%d,%p\n",*p,p);
	 */
	//--------------如果是第一次運行，
	//--------------則返回一個沒有映射的空間首地址
	//--------------同時產生一個數據：指向這個地址
	int* q = (int*)sbrk(0);
	//---地址+4個字節
	brk(q+1);
	*q = 8888;
	//釋放
	brk(q);
	printf("%d,%p\n",*q,q);
	return 0;
}

