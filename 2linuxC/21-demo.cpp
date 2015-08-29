/*
 * =====================================================================================
 *
 *       Filename:  21-demo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月05日 20时25分43秒
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

class P{
	public:
		virtual void show(){
			cout << "P.....show....." << endl;
		}
};

class C : public P{
	public:
		void show(){
			cout << "C....show................." << endl;
		}
};

int main(){
	P* p = new P;
	C* c = new C;
	P* p2 = new C;
	P* p3 = c;
	C c2;
	P p4 = c2;
	P* p5 = &c2;
	P& p6 = c2;

	p->show();
	c->show();
	p2->show();
	p3->show();
	p4.show();
	p5->show();
	p6.show();

	return 0;
}

