/*
 * =====================================================================================
 *
 *       Filename:  3-04insert.cpp
 *
 *    Description:  插入法排序
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 14时09分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
void sort(int* a,int n){
	//反復從第二個數據開始插入適當位置
	int j;	
	for(int i = 1; i < n ; i ++){
		int t = a[i];
		for(j = i ; j > 0 && t < a[j - 1] ; j --){
			a[j] = a[j-1];
		}
		a[j] = t;
	}
}

