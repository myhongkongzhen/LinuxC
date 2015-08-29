/*
 * =====================================================================================
 *
 *       Filename:  3-11find_count.cpp
 *
 *    Description:  find,count用法
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 04时10分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
//#include <ctype.h>
using namespace std;

bool init_upper(const string& str){
	return isupper(str[0]);
}

bool has_c(const string& str){
	return str.find_first_of("i") != string::npos;
}

int main(){
	string a[] = {"Aran","Jun","tani","Mizu"};
	string* p = find(a,a+4,"tani");
	if(p == a+4){
		cout << "Not Match->" << *p << endl;
	}else{
		cout << "Match->" << *p << endl;
	}
	cout << "========================" << endl;
	p = find_if(a,a+4,init_upper);
	if(p == a+4){
		cout << "Not Match->" << *p << endl;
	}else{
		cout << "Match->" << *p << endl;
	}
	cout << count_if(a,a+4,init_upper) << endl;
	cout << count_if(a,a+4,has_c) << endl;
	return 0;
}

