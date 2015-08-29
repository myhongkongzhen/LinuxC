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

typedef string T;

class Stack{
	T data[5];
	int cur;
	public:
	Stack():cur(0){}
	//對象本身所佔內存空間，沒有其他操作，
	//不用析構，默認的即可
	//~Stack(){}
	Stack& push(const T& data);//入棧
	T pop();//出棧,下一個數據成為棧頂
	const T& top()const;//取得棧頂數據
	bool empty()const;
	bool full()const;
	void clear();//清空(復位)
	int size()const;
};

int Stack::size()const{
	return cur;
}

void Stack::clear(){
	//一個數組是否有數據：是否有有效數據
	//將這些數據當做是無效數據
	cur = 0;
}

bool Stack::full()const{
	return (cur == 5);
}

bool Stack::empty()const{
	return (cur == 0);
}

const T& Stack::top()const{
	if(empty()){
		throw "EMPTY";
	}
	return data[cur-1];
}

T Stack::pop(){
	if(empty()){
		throw "EMPUT";
	}	
	return  data[--cur];
}

Stack& Stack::push(const T& data)/* throw (const char*)*/{
	if(full()){
		throw "FULL";
	}
	this->data[cur++] = data;
	return *this;
}

int main(){
	Stack s;
	try{
		s.push("tani").push("jun").push("mizu").push("aran");
		cout << s.size() << '~';
		while(!s.empty()){
			cout << s.pop() << endl;
		}
		s.push("yuki");
		s.push("tani").push("jun").push("mizu");
		s.push("aran").push("yuhi");
		cout << s.size() << '~';
		cout << s.top() << endl;
	}catch(const char* e){
		cout << e << endl;
	}
	return 0;
}

