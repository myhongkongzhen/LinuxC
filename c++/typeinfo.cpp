/*
 * =====================================================================================
 *
 *       Filename:  typeinfo.cpp
 *
 *    Description:  typeinfo測試
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 12时26分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <typeinfo>
using namespace std;

class A{
	public:
		virtual void f(){}
		A(){}
		~A(){}
};

class B:public A{
	public:
		B(){}
		~B(){}
};
class C:public B{
	public:
		C(){}
		~C(){}
};
class D:public A{
	public:
		D(){}
		~D(){}
};

int main(){
	A* p1 = new A;
	A* p2 = new B;
	A* p3 = new C;
	A* p4 = new D;
	A* p5 = new B;
	//運行時類型識別
	cout << typeid(*p1).name() << endl;
	cout << typeid(*p4).name() << endl;
	cout << (typeid(*p2) == typeid(*p5)) << endl;
	//before不工作
	//	cout << typeid(*p2).before(typeid(*p3)) << endl;
	const type_info& t = typeid(*p4);
	cout << t.name() << endl;
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	return 0;
}




