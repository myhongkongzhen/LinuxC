/*
 * =====================================================================================
 *
 *       Filename:  reference_3.cpp
 *
 *    Description:  引用做返回類型
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 08时21分31秒
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

int& max(int& a,int& b){
	return ((a>b)?a:b);
}

void print(const int& a,const int& b){
	cout << a << '\t' << b << endl;
}

//返回局部變量的引用，需要static或是alloc，new申請的動態內存空間的變量才行，否則是不安全的
int& counter(){
	static int cnt = 0;
	return ++cnt;
}

int main(){
	int a = 4;
	int b = 54;
	print(a,b);
	cout << max(a,b) << endl;
	max(a,b) += 100;
	print(a,b);
	counter() = 1000;
	cout << counter() << endl;
	cout << counter() << endl;
	cout << counter() << endl;
	cout << counter() << endl;
	return 0;
}





