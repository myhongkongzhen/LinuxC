/*
 * =====================================================================================
 *
 *       Filename:  3-09copy.cpp
 *
 *    Description:  通用算法copy
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 03时31分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#include "3-print.h" 

template < typename Iter, typename Pos >
void copy_n(Iter ib,Iter ie,Pos p){
	while(ib != ie){
		*p++ = *ib++;	
	}
}

int main(){
	int a[] = {2,3,6,8,9};
	int b[8] = {0};
	vector<int> vi(a,a+5);
	print(vi.begin(),vi.end(),'|');
	sort(vi.begin(),vi.end());
	print(vi.begin(),vi.end(),'|');
	cout << "--------------------" << endl;
	print(a,a+5,',');
	copy(vi.begin(),vi.end(),a);
	print(a,a+5,',');
	copy_n(vi.begin(),vi.end(),b);
	cout << "--------------------" << endl;
	print(b,b+8,',');
	copy_backward(b,b+5,b+8);
	print(b,b+8,',');
	bool func(int);
	vector<int> v;
	deque<int> vq;
	remove_copy_if(a,a+5,back_inserter(v),func);
	print(v.begin(),v.end(),'|');
	//------------後插入
	copy_n(a,a+5,back_inserter(vq));
	print(vq.begin(),vq.end(),',');
	//------------前插入
	copy_n(a,a+5,front_inserter(vq));
	print(vq.begin(),vq.end(),',');
	return 0;
}

bool func(int n){
	//判斷是否是奇數，是true，否false,偶數
	return n & 1;
}

