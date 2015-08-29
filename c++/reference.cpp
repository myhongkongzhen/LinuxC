/*
 * =====================================================================================
 *
 *       Filename:  reference.cpp
 *
 *    Description:  引用
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 10时32分56秒
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

int main(){
	double d = 123.45;
	//e是一個引用，是一個變量的別名
	//引用必須用變量初始化
	double& e = d;
	//用常量初始化，必須加上const
	const double& c = 34.64;
	//也可以用臨時值初始化，同樣必須加上const
	const double& s = d + 34;
	cout << "&d = " << &d << endl;
	cout << "&e = " << &e << endl;
	cout << "c = " << c << endl;
	cout << "s = " << s << endl;
	return 0;
}	

