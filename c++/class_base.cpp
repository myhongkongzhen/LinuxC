/*
 * =====================================================================================
 *
 *       Filename:  class.cpp
 *
 *    Description:  自定義類型
 *
 *        Version:  1.0
 *        Created:  2014年07月29日 20时41分07秒
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

//成員默認都是公開的
struct PS{
	string name;
	int age;

	void show(){
		cout << name << "----" << age << endl;
	}

};

//默認是私有的數據
//公開訪問數據的函數
class PC{
	string name;
	int age;

	public:
	//構造函數
	PC(const char* name,int a){
		//可以指定哪個域中的變量名
		PC::name = name;	
		age = a;
	}

	void show(){
		cout << name << "====" << age << endl;
	}

};

int main(){
	PS s = {"yuhi",33};
	//PC c ;
	//不可以像結構體一樣的初始化，因為默認是私有的
	//PC c = {"jun",23};
	//這樣初始化
	PC c("jun",23);
	//PC d;//可保證對象里沒有垃圾數據

	/* 	s.name = "tani";
	 * 	s.age = 30;
	 */
	s.show();
	//C++中class中的成員默認都是私有的
	//c.name = "jun";
	//c.show();

	c.show();	

	return 0;
}






