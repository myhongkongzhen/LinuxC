/*
 * =====================================================================================
 *
 *       Filename:  2-01sort.cpp
 *
 *    Description:  標準函數庫
 *
 *        Version:  1.0
 *        Created:  2014年08月08日 21时11分34秒
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
#include <algorithm>
using namespace std;

class Person{
	string name;
	int age;
	public:
	Person(const char* name,int age):name(name),age(age){}
	bool operator < (const Person& p)const{
		if(this->name <= p.name){
			return true;
		}
		return false;
	}	
	friend ostream& operator << (ostream& o,const Person& p){
		return o << p.name << ':' << p.age ;
	}
};

template < typename T >
void print(T b,T e){
	while(e != b){
		cout << *b++ << ' ';
	}
	cout << endl;
}

int main(){
	int a[6] = {4,2,5,2,1,7};
	double d[4] = {4.5,7.5,2.2,0.8};
	string s[4] = {"jun","aran","tani","mizu"};
	Person p[3] = {Person("mizu",23),
		Person("tani",22),Person("jun",24)};
	sort(a,a+6);//含頭不含尾的區間[....);
	sort(d,d+4);
	sort(s,s+4);
	sort(p,p+3);
	print(a,a+6);
	print(d,d+4);
	print(s,s+4);
	print(p,p+3);
	return 0;
}

