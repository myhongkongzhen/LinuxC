/*
 * =====================================================================================
 *
 *       Filename:  1-05autoptr.cpp
 *
 *    Description:  自動指針
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 19时27分40秒
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

template < typename T >
class autoptr{
	T* p;
	public:
	autoptr(T* p):p(p){}
	~autoptr(){delete p;}
	autoptr& operator =(autoptr& a){
		if(this == &a){
			delete p;
		}
		if(p){
			delete p;
		}
		p = a.p;
		a.p = NULL;
		return *this;
	}
	T& operator *()const{
		return *p;
	}
	T* operator ->()const{
		return p;
	}
	autoptr(autoptr& a):p(0){
		operator =(a);
	}
};

class A{
	int data;
	public:
	A(int data):data(data){
		cout << this ;
		cout <<"-----A--->" << data<< endl;
	}
	~A(){cout << this << "--------~A()" << data << endl;}
	void show()const{
		cout << this << "-----" << data << endl;	
	}
};

int main(){
	autoptr<A> p(new A(10));
	p->show();
	autoptr<A> q(p);
	//p->show();//p已經被釋放，賦值給q了
	q->show();
	autoptr<A> r(new A(30));
	r->show();
	r = q;
	return 0;
}

