/*
 * =====================================================================================
 *
 *       Filename:  3-05set.cpp
 *
 *    Description:  set不允許重複的數據
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 02时09分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <set>
#include <string>
#include <fstream>
using namespace std;
#include "3-print.h"

int main(){
	set<string> s;
	string str;
	ifstream fin("file.txt");
	if(!fin){
		return 1;
	}
	while(fin >> str){
		s.insert(str);
	}
	print(s.begin(),s.end(),'\n');
	return 0;
}

