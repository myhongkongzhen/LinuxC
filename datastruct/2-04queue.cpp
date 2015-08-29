/*
 * =====================================================================================
 *
 *       Filename:  2-04queue.cpp
 *
 *    Description:  隊列
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 19时09分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

typedef int T;
#include "2-01link.h" 

class Queue{
	List list;
	public:
	Queue& push(const T& data){
		list.push_back(data);
		return *this;
	}
	T pop(){
		T t = front();
		list.erase(0);
		return t;
	}
	const T& front()const{
		return list.front();
	}
	const T& back()const{
		list.back();
	}
	int size()const{
		return list.size();
	}
	void clear(){
		list.clear();
	}
	bool empty()const{
		return list.empty();
	}
	bool full()const{
		return false;
	}
};

int main(){
	Queue q;
	q.push(1).push(2).push(3).push(4);
	cout <<	q.pop() << endl;
	cout << q.pop() << endl;
	q.push(5).push(6).push(7);
	cout << '~'  << q.size() << endl;
	while(!q.empty()){
		cout << q.pop() << ' ';
	}
	cout << endl;
	cout << '~'  << q.size() << endl;
	return 0;
}

