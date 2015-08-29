/*
 * =====================================================================================
 *
 *       Filename:  3-06multiset.cpp
 *
 *    Description:  multiset可重複的K
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 02时25分02秒
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
#include <map>
#include <string>
using namespace std;
#include "3-print.h"

int main(){
	multiset<string> ms;
	string name;
	cout << "please input name:(end) " ;
	//ctrl + d 輸入結束
	while(cin >> name){
		ms.insert(name);
	}
	cout << endl;
	print(ms.begin(),ms.end(),'|');
	multimap<int,string> m;
	multiset<string>::iterator ib = ms.begin();
	multiset<string>::iterator ie;
	while(ib != ms.end()){
		//---------------------統計
		m.insert(make_pair(ms.count(*ib),*ib));
		ib = ms.upper_bound(*ib);
	}
	print(m.begin(),m.end(),'\n');

	return 0;
}


