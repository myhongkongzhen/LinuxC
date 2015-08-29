/*
 * =====================================================================================
 *
 *       Filename:  2-03sequence.cpp
 *
 *    Description:  序列式容器
 *
 *        Version:  1.0
 *        Created:  2014年08月09日 20时12分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include "print.h"

int main(){
	deque<string> ds;
	//必須有空格，新標準可以自動識別，但還沒有實施
	//deque< vector<int> > fvi;
	ds.push_back("mizu");
	ds.push_back("tani");
	ds.push_back("jun");
	ds.push_back("aran");
	print(ds.begin(),ds.end(),',');	
	ds.insert(++++ds.begin(),2,"kashi");
	print(ds.begin(),ds.end(),',');	
	string s[] = {"yuhi","yu","so"};
	ds.insert(----ds.end(),s,s+3);
	print(ds.begin(),ds.end(),',');	
	sort(ds.begin(),ds.end());
	print(ds.begin(),ds.end(),',');	
	//返回的是首尾數據的引用
	cout << ds.front() << "==" << ds.back() << endl;
	ds.front() = "ume";
	ds.back() = "sumika";
	cout << ds.front() << "==" << ds.back() << endl;
	print(ds.begin(),ds.end(),',');	
	ds.erase(++++++ds.begin());
	ds.pop_back();
	print(ds.begin(),ds.end(),',');	
	ds.resize(10,"yuki");
	print(ds.begin(),ds.end(),',');	
	ds.assign(5,"Amami Yuki");
	print(ds.begin(),ds.end(),',');	
	return 0;
}

