/*
 * =====================================================================================
 *
 *       Filename:  3-02map.cpp
 *
 *    Description:  map個性
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 00时41分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;
#include "3-print.h"

class Person{
	string name;
	int age;
	public:
	Person(){}
	Person(const char* name,int age = 0):name(name),age(age){}
	friend ostream& operator << (ostream& o,const Person& p){
		return o << p.name << '~' << p.age;
	}
};

int main(){
	//--K--,V
	//K必須支持<運算符,默認以<小於排序
	map<int,Person> m;
	//用函數模板
	m.insert(make_pair(2,Person("tani",20)));
	m.insert(make_pair(4,Person("aran",25)));
	//pair類型
	m.insert(pair<int,Person>(1,Person("mizu",23)));
	print(m.begin(),m.end(),'|');
	//下標沒有時，增加新的
	m[6] = Person("kashi",24);
	m[7] = Person("yuki",45);
	//內部類型
	m.insert(map<int,Person>::value_type(3,Person("jun",24)));
	m.insert(make_pair(7,Person("yuhi",24)));
	m.insert(make_pair(7,Person("yuki",44)));
	m[5] = Person("yuhi",24);
	print(m.begin(),m.end(),'|');
	//下標數據存在時，修改原值
	m[7] = Person("komu",25);
	print(m.begin(),m.end(),'|');
	return 0;
}

