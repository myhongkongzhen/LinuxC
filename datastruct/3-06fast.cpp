/*
 * =====================================================================================
 *
 *       Filename:  3-06fast.cpp
 *
 *    Description:  快速排序
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 16时25分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <algorithm>
using std::swap;

void sort(int* a,int n){
	//一個數據
	if(n <= 1){
		return;
	}
	//兩個數據
	if(n == 2){
		if(a[1] < a[0]){
			swap(a[1],a[0]);
			return;
		}
	}

	//開始分組
	//將臨界值放到最左邊
	swap(a[n/2],a[0]);
	int tmp = a[0];
	int* l = a+1;
	int* r = a+n-1;
	//左右指針不交叉的時候
	while(l<r){
		//做指針值小於臨界值並且指針不交叉右指針
		while(l < r && *l < tmp ){
			++l;
		}
		while(a < r && !(*r < tmp)){
			--r;
		}
		if(l<r){
			swap(*l,*r);
		}
	}
	if(*r < tmp){
		swap(*r,a[0]);
	}

	//左右兩組數據繼續查找 
	sort(a,r-a);
	sort(r+1,n-1-(r-a));
}

