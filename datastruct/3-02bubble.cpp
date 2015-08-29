/*
 * =====================================================================================
 *
 *       Filename:  3-02bubble.cpp
 *
 *    Description:  冒泡排序
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 13时17分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <algorithm>
using namespace std;

void sort(int* a,int n){
	bool changed = true;
	do{
		changed = false;
		for(int i = 1 ; i < n ; i ++){
			if(a[i-1]> a[i]){
				swap(a[i-1],a[i]);
				changed = true;
			}
		}
		--n;
	}while(changed);
}

