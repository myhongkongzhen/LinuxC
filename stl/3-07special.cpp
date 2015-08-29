/*
 * =====================================================================================
 *
 *       Filename:  3-07special.cpp
 *
 *    Description:  stack,queue,priotity_queue 優先隊列
 *					沒有迭代器，特殊容器
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 02时52分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	priority_queue<int> pq;
	pq.push(34);
	pq.push(40);
	pq.push(31);
	pq.push(98);
	pq.push(43);
	pq.push(25);
	pq.push(99);
	while(!pq.empty()){
		//對於優先隊列，使用top帶回數據
		cout << pq.top() << '\n' ;
		//pop不帶回數據，top或front，back才帶回數據
		//pop出隊列
		pq.pop();
	}
	return 0;
}


