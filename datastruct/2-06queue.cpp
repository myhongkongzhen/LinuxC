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

class Queue{
	T data[5];
	int b,n;//對首位置和有效元素個數
	public:
	Queue():b(0),n(0){}
	Queue& push(const T& data){
		if(full()){
			throw "FULL";
		}
		this->data[(b+n++)%5] = data;
		return *this;
	}
	T pop(){
		if(empty()){
			throw "EMPTY";
		}
		--n;
		return data[b++%5];
	}
	const T& front()const{
		return data[b%5];
	}
	const T& back()const{
		return data[(b+n-1)%5]; 
	}
	int size()const{
		return n;
	}
	void clear(){
		n = 0;
		b = 0;
	}
	bool empty()const{
		return (n == 0);
	}
	bool full()const{
		return (n == 5);
	}
};

int main(){
	Queue q;
	try{
		q.push(1).push(2).push(3).push(4);
		cout <<	q.pop() << endl;
		cout << q.pop() << endl;
		q.push(5).push(6).push(7);
		q.push(8).push(16).push(17).push(18);
	}catch(const char* e){
		cout << "ERROR : " << e << endl;
	}
	cout << '~'  << q.size() << endl;
	while(!q.empty()){
		cout << q.pop() << ' ';
	}
	cout << endl;
	cout << '~'  << q.size() << endl;
	try{
		cout << q.pop() << endl;
	}catch(const char* e){
		cout << "ERROR : " << e << endl;
	}
	return 0;
}

