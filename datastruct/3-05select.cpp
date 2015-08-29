/*
 * =====================================================================================
 *
 *       Filename:  3-05select.cpp
 *
 *    Description:  選擇排序
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 14时34分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

int getmin(int* a,int n,int s);

void sort(int* a,int n){
	//反復n-1次
	//第i次從第i~n個數據中找到最小元素跟第i個元素交換
	//for(int i = 0; i < n - 1 ; i ++){
	for(int i = 1; i < n ; i ++){
		int minflag = i - 1;
		for(int j = i ; j < n ; j ++){
			if(a[j] < a[minflag]){
				minflag = j;
			}
		}
		swap(a[i-1],a[minflag]);
	}	
}


