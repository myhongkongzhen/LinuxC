/*
 * =====================================================================================
 *
 *       Filename:  autoptr.cpp
 *
 *    Description:  自動指針,調用析構函數,動態內存自動釋放
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 19时19分55秒
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
using namespace std;

struct date{
	int year;
	int month;
	int day;
};

struct Person{
	string name;
	int age;
	bool gender;
	double salary;
	date birth;
	Person(){
		cout << "--struct Person("<< this <<")--" << endl;	
		age = 99;
	}
	~Person(){
		cout << "++struct ~Person("<< this <<")++" << endl;	
	}
};

class autoptr{
	Person* p;
	//靜態數據成員初始化，在類外部
	static int cnt;
	public:
	autoptr(Person* p):p(p){++cnt;}
	//拷貝構造函數：本類對象的引用
	autoptr(const autoptr& a):p(a.p){++cnt;}
	~autoptr(){
		cout << cnt << "~~~~" << endl;
		if(--cnt == 0){
			delete p;	
			p = NULL;
		}
	}
	Person* operator->(){
		return p;
	}
	Person& operator*(){
		return *p;
	}
};

//靜態數據成員初始化，在類外部
int autoptr::cnt = 0;

int main(){
	//	Person* a = new Person;
	autoptr a = new Person;//a.cnt == 1
	//拷貝構造函數
	//兩個指針指向同個地址，析構的時候，兩個都會釋放
	//造成重複釋放，段錯誤
	autoptr b = a;//b.cnt == 2
	autoptr c = a;//c.cnt == 2
	autoptr e = b,g(b),f(a);
	a->name = "mizu";//a.operator->()->name;
	a->birth.year = 1990;
	cout << c->age << endl;
	cout << (*a).name << endl;
	//	cout << a->name << endl;
	cout << b->birth.year << endl;
	cout << g->birth.year << endl;
	b = a;
	return 0;
}



