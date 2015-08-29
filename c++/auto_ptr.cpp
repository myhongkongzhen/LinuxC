/*
 * =====================================================================================
 *
 *       Filename:  auto_ptr.cpp
 *
 *    Description:  自動指針
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 22时31分09秒
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
		A(){cout << "construct A:" << this << endl;}
		~A(){cout << "deconstruct A:" << this << endl;}
};
class B{
	public:
		B(){cout << "construct b:" << this << endl;}
		~B(){cout << "deconstruct b:" << this << endl;}
};
class D{
	public:
		D(){cout << "construct d:" << this << endl;}
		~D(){cout << "deconstruct d:" << this << endl;}
};
class C{ 
	auto_ptr<D> p;
	public:
	C(int n){
		auto_ptr<D> q(new D);
		if(n < 0){
			throw 88;
		}
		p = q;
		cout << "construct c:" << this << endl;
	}
	~C(){
		//delete p;
		cout << "deconstruct c:" << this << endl;
	}
};

int main(){
	try{
		//A* p = new A;
		auto_ptr<A> p(new A);//拋出異常后，析構函數會自動調用
		B* q(new B);//不會自動調用析構函數，不會釋放內存空間
		C oc(-3);
		throw 123;
		//delete p;
		//p = NULL;
		delete q;
		q = NULL;
	}catch(int e){
		cout << "exception:" << e << endl;
	}catch(...){
		cout << "..." << endl;
	}
	return 0;
}

