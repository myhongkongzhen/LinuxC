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

int main(){
	map<int,string> m;
	//用函數模板
	m.insert(make_pair(2,"tani"));
	m.insert(make_pair(4,"aran"));
	//pair類型
	m.insert(pair<int,string>(1,"mizu"));
	print(m.begin(),m.end(),',');
	//下標沒有時，增加新的
	m[6] = "kashi";
	m[7] = "yuki";
	//內部類型
	m.insert(map<int,string>::value_type(3,"jun"));
	m.insert(make_pair(7,"yuhi"));
	m.insert(make_pair(7,"yuki"));
	m[5] = "yuhi";
	print(m.begin(),m.end(),',');
	//下標數據存在時，修改原值
	m[7] = "komu";
	print(m.begin(),m.end(),',');
	return 0;
}

