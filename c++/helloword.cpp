/*
 * =====================================================================================
 *
 *       Filename:  helloword.cpp
 *
 *    Description:  c++程序
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 08时48分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

//using namespace std;
//A::B表示A範圍內的B，“::”稱為域操作符
using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "please input name and age:" << endl;
	//直接引入
	std::string name;
	int age;
	cin >> name >> age;
	cout << name << " -- " << age << endl;
	return 0;
}




