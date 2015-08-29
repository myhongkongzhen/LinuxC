/*
 * =====================================================================================
 *
 *       Filename:  enum_cpp.cpp
 *
 *    Description:  c++中的枚舉類型 
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 10时13分42秒
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

enum Course{UNIX,C,CPP,UC,VC};
struct Student{
	string name;
	int age;
};

int main(){
	//c++中自定義類型，不再使用typedef和類型關鍵字，而是直接使用類型名即可
	//typedef Course course;	
	Course c;
	Student s;
	int n;
	c = CPP;
	//枚舉類型提升成int類型是可以的，自動提升
	n = CPP;
	//c = n;//c不當成一個int類型，而是一個Course類型
	return 0;
}


