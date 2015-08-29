/*
 * =====================================================================================
 *
 *       Filename:  3-04multimap.cpp
 *
 *    Description:  multimap個性
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 01时25分38秒
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
	multimap<string,double> m;
	/* 
	 * pair 對
	 * pair<M,N>(first,second);
	 * 第一個值通過first取得
	 * 第二個值通過second取得
	 * */
	//insert時候，插入的是一個pair
	m.insert(make_pair("tani",24334.56));
	m.insert(make_pair("mizu",6762.9));
	m.insert(pair<string,double>("aran",85445.6));
	m.insert(make_pair("jun",189034.56));
	typedef multimap<string,double> msd;
	m.insert(msd::value_type("tani",9314.56));
	print(m.begin(),m.end(),'|');
	msd::iterator ib = m.begin();
	msd::iterator ie; 
	map<string,double> cnt;
	while(ib != m.end()){
		string name = ib->first;
		ie = m.upper_bound(name);
		double sum = 0.0;
		while(ib!=ie){
			sum += ib++->second;
		}
		cnt.insert(make_pair(name,sum*0.03));
	}
	print(cnt.begin(),cnt.end(),'|');
	return 0;
}

