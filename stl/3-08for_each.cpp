/*
 * =====================================================================================
 *
 *       Filename:  3-08func.cpp
 *
 *    Description:  通用算法
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 03时17分48秒
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
using namespace std;

void add10(int& i){
	i += 10;
}

void print(const int i){
	cout << i << '|';
}

class add{
	int data;
	public:
	add(int data):data(data){}
	void operator()(int& e){
		e += data;
	}
};

template < typename Iter,typename Func >
void foreach(Iter ib, Iter ie, Func f){
	while(ib != ie){
		f(*ib++);
	}
}

int main(){
	int a[] = {11,22,33,44,55};
	for_each(a,a+5,print);
	cout << endl;
	//--------------函數
	for_each(a,a+5,add10);
	for_each(a,a+5,print);
	cout << endl;
	//--------------函數對象
	//--------------支持()圓括號運算符，
	//--------------像函數一樣使用
	for_each(a,a+5,add(80));
	for_each(a,a+5,print);
	cout << endl;
	//--------------函數對象
	//--------------支持()圓括號運算符，
	//--------------像函數一樣使用
	for_each(a,a+5,add(6));
	for_each(a,a+5,print);
	cout << endl;
	cout << "-------------------------" << endl;
	foreach(a,a+5,add(78));
	foreach(a,a+5,print);
	cout << endl;
	return 0;
}


