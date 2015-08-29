/*
 * =====================================================================================
 *
 *       Filename:  demo.cpp
 *
 *    Description:  test
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 11时43分27秒
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

class A{
	public:
		virtual void show();
};

void A::show(){
	cout << "-----AAAAAAAA-----" << endl;	
}
class B:public A{
	public:
		void show(){
			cout << "-----BBBBBBBB-----" << endl;	
		}
};

int main(){
	A a;
	B b;
	A* pa = &a;
	A* pb = &b;

	pa->show();
	pb->show();

	return 0;
}




