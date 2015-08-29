/*
 * =====================================================================================
 *
 *       Filename:  inline.cpp
 *
 *    Description:  內斂函數
 *
 *        Version:  1.0
 *        Created:  2014年07月29日 19时34分17秒
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

inline void f1(){
	cout << "f1()" << endl;
}
inline int f2(int n) {
	cout << "f2()" << n * n << endl;
	return n;
}
inline int f3(int n){
	cout << "f3()" << n * n << endl;
	if ( n < 2){
		return 555;
	}
	return n * f3(n-1);
}
int main(){
	f1();
	cout << f2(5) << endl;
	cout << f3(66) << endl;
	return 0;
}




