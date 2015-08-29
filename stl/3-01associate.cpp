/*
 * =====================================================================================
 *
 *       Filename:  3-01associate.cpp
 *
 *    Description:  關聯式容器共性
 *
 *        Version:  1.0
 *        Created:  2014年08月09日 23时30分18秒
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
#include <set>
#include "print.h"

struct Person{
	string name;
	int age;
	Person(const char* name,int age):name(name),age(age){}
};

bool operator < (const Person& p1,const Person& p2){
	return p1.name < p2.name || \
		p1.name == p2.name && p1.age < p2.age;
}

ostream& operator << (ostream& o,const Person& p){
	return o << p.name << ':' << p.age ;
}

int main(){
	//multiset<Person> mp(compare_fun);
	multiset<Person> mp;
	mp.insert(Person("mizu",22));
	mp.insert(Person("jun",23));
	mp.insert(Person("yuki",44));
	mp.insert(Person("tani",20));
	mp.insert(Person("aran",25));
	mp.insert(Person("yuki",40));
	mp.insert(Person("yu",33));
	mp.insert(Person("so",30));
	mp.insert(Person("yuki",44));
	mp.insert(Person("ume",20));
	print(mp.begin(),mp.end(),'\n');
	multiset<Person>::iterator it = mp.find(Person("tani",20));
	if(it == mp.end()){
		cout << "Not found!" << endl;
	}else{
		cout << "Match:" << *it << endl;	
	}
	it = mp.find(Person("wao",20));
	if(it == mp.end()){
		cout << "Not found!" << endl;
	}else{
		cout << "Match:" << *it << endl;	
	}
	cout << mp.count(*(mp.find(Person("yuki",44)))) << endl;
	multiset<Person>::iterator ib,ie;
	ib = mp.lower_bound(Person("yuki",44));
	ie = mp.upper_bound(Person("yuki",44));
	cout << "------------------" << endl;
	print(ib,ie);
	cout << "------------------" << endl;
	pair< multiset<Person>::iterator,\
		multiset<Person>::iterator > p =\
		mp.equal_range(Person("yuki",44));
	print(p.first,p.second);
	cout << "===========" << endl;
	typedef multiset<Person>::iterator mpi;
	pair<mpi,mpi> q = mp.equal_range(Person("yuki",44));
	print(q.first,q.second);
	mp.erase(Person("yuki",44));
	print(mp.begin(),mp.end(),',');
	return 0;
}

