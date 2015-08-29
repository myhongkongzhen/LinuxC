/*
 * =====================================================================================
 *
 *       Filename:  2-06list.cpp
 *
 *    Description:  雙向鏈錶個性
 *
 *        Version:  1.0
 *        Created:  2014年08月09日 22时20分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <list>
#include <cassert>
using namespace std;
#include "print.h"

int main(){
	int a[] = {33,22,8,8,8,55,11,8,8,44};
	list<int> li(a,a+10);
	print(li.begin(),li.end());
	li.unique();
	print(li.begin(),li.end());
	li.sort();
	print(li.begin(),li.end());
	li.unique();
	print(li.begin(),li.end());
	li.reverse();
	print(li.begin(),li.end());
	int b[] = {99,33,67,56,89,44};
	list<int> il(b,b+6);
	print(il.begin(),il.end());
	li.splice(li.begin(),il);
	cout << "----------------------" << endl;
	assert(il.empty());
	print(li.begin(),li.end());
	li.remove(44);
	print(li.begin(),li.end());
	li.sort();
	print(li.begin(),li.end());
	li.unique();
	print(li.begin(),li.end());
	il.push_back(0);
	il.push_back(3);
	il.push_back(67);
	il.push_back(89);
	il.push_back(23);
	print(il.begin(),il.end());
	il.sort();
	print(il.begin(),il.end());
	cout << "++++++++++++++++++++" << endl;
	li.merge(il);
	assert(il.empty());
	print(li.begin(),li.end());
	li.unique();
	print(li.begin(),li.end());
	li.sort(greater<int>());
	print(li.begin(),li.end());
	cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
	//自定義排序規則
	bool compare(int x,int y);
	//函數指針，函數地址&
	li.sort(compare);
	print(li.begin(),li.end());

	return 0;
}

bool compare(int x,int y){
	x %= 3;
	y %= 3;
	return x<y;
}

