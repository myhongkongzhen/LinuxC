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
	int cur;
	public:
	Queue():cur(0){}
	Queue& push(const T& data){
		if(full()){
			throw "FULL";
		}
		this->data[cur++] = data;
		return *this;
	}
	T pop(){
		T t = data[0];	
		for(int i = 1 ; i < cur; i ++){
			data[i-1] = data[i];
		}
		--cur;
		return t;
	}
	const T& front()const{
		return data[0];
	}
	const T& back()const{
		return data[cur-1]; 
	}
	int size()const{
		return cur;
	}
	void clear(){
		cur = 0;
	}
	bool empty()const{
		return (cur == 0);
	}
	bool full()const{
		return (cur == 5);
	}
};

int main(){
	Queue q;
	try{
		q.push(1).push(2).push(3).push(4);
		cout <<	q.pop() << endl;
		cout << q.pop() << endl;
		q.push(5).push(6).push(7).push(8);
		cout << '~'  << q.size() << endl;
		while(!q.empty()){
			cout << q.pop() << ' ';
		}
		cout << endl;
		cout << '~'  << q.size() << endl;
	}catch(const char* e){
		cout << "ERROR : " << e << endl;
	}
	return 0;
}

