/*
 * =====================================================================================
 *
 *       Filename:  1-03stack.cpp
 *
 *    Description:  棧，先進後出
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 17时10分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

typedef int T;
#include "2-01link.h" 

class Stack{
	//組合
	List list; 
	public:
	Stack& push(const T& data);//入棧
	T pop();//出棧,下一個數據成為棧頂
	const T& top()const;//取得棧頂數據
	bool empty()const;
	bool full()const;
	void clear();//清空(復位)
	int size()const;
};

int Stack::size()const{
	return list.size();
}

void Stack::clear(){
	list.clear();
}

bool Stack::full()const{
	return false;
}

bool Stack::empty()const{
	return list.empty();
}

const T& Stack::top()const{
	return list.front();
}

T Stack::pop(){
	T data = list.front();
	list.erase(0);
	return  data;
}

Stack& Stack::push(const T& data)/* throw (const char*)*/{
	list.push_front(data);
	return *this;
}

int main(){
	Stack s;
	try{
		s.push(4).push(5).push(6).push(7);
		cout << s.size() << '~' << endl;
		while(!s.empty()){
			cout << s.pop() << endl;
		}
		s.push(8);
		s.push(9).push(13).push(20);
		s.push(11).push(12);
		cout << s.size() << '~';
		cout << s.top() << endl;
	}catch(const char* e){
		cout << e << endl;
	}
	return 0;
}

