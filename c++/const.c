/*
 * =====================================================================================
 *
 *       Filename:  const.c
 *
 *    Description:  const對gcc與g++編譯產生不同結果
 *					gcc編譯時，m和n的值都會改變
 *					g++編譯時，c++編譯器做了大量的優化
 *					將效率提到最高，盡量少去訪問內存
 *					因此n的值不會改變，而m的值會改變
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 10时57分45秒
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
	/*
	 * gcc編譯時，m和n的值都會改變
	 * g++編譯時，因為c++編譯器做了大量的優化，
	 * 將效率提到最高，盡量少去訪問內存
	 * 因此n的值不會改變，而m的值會改變
	 * volatile每次都從內存中讀取數據值
	 */
	const int n = 100;//g++編譯時，直接使用100
	volatile const int m = 23;//每次都到內存中讀取m的值
	//這裡是不合理的操作
	int* p = (int*)&n;
	*p = 32;
	//這裡是不合理的操作
	p = (int*)&m;
	*p = 200;
	printf("n = %d , m = %d\n",n,m);
	return 0;
}



