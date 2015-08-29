/*
 * =====================================================================================
 *
 *       Filename:  virtual_2.cpp
 *
 *    Description:  虛函數
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 15时36分50秒
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
	double d;
};
class B:public A{
	double d;
	public:
	void f(){}
};
class C{
	double d;
	public:
	virtual ~C(){}
	/*
	 * 有虛函數的類，隱含的指針，指向虛函數表
	 * 虛函數表儲存著這個類的所有虛函數的地址
	 * 每個類只有一個虛函數表
	 */
	virtual void f(){cout << "C" << endl;}
	virtual void g(){cout << this << "--" << &d << endl;}
};
class D:public C{
	double d;
	public:
	virtual void f(){cout << "D" << endl;}
	virtual void g(){}
	virtual void h(){}
	virtual void i(){}
	virtual void j(){}
	virtual ~D(){}
};

int main(){
	A* p = new B;
	C* p1 = new C;
	C* p2 = new D;
	p1->f();	
	p2->f();
	cout << p1 << endl;
	p1->g() ;
	//前8個字節是虛表指針
	memcpy(p2,p1,8);
	p2->f();
	delete p;
	delete p1;
	delete p2;
	/* 
	 * 	cout << sizeof(int) << endl;
	 * 	cout << sizeof(short) << endl;
	 * 	cout << sizeof(char) << endl;
	 * 	cout << sizeof(float) << endl;
	 * 	cout << sizeof(double) << endl;
	 * 	cout << "----------------------" << endl;
	 * 	cout << sizeof(A) << endl;
	 * 	cout << sizeof(B) << endl;
	 * 	cout << sizeof(C) << endl;
	 * 	cout << sizeof(D) << endl;
	 */
	return 0;
}




