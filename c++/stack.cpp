/*
 * =====================================================================================
 *
 *       Filename:  stack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 20时11分51秒
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

typedef string T;
class Stack{
	typedef unsigned int uint;
	T* mem;  
	uint max;
	uint len;
	public:
	Stack(const Stack& s):mem(new T[s.max]),max(s.max),len(s.len){}
	Stack(uint n):mem(new T[n]),max(n),len(0){}
	uint getMax()const{ return max; }
	uint size()const{ return len; }
	Stack& push(const T& t){
		if(len >= max){
			throw 0;
		}
		mem[len++] = t;
		return *this;
	}
	T& pop(){
		if(len == 0){
			throw 0;
		}
		return mem[--len];
	}
	void print()const{
		for(uint i = 0 ; i < len  ; i ++){
			cout << mem[i] << ' ';
		}
		cout << endl;
	}
	~Stack(){delete[] mem;}
	Stack& operator=(const Stack& rh){
		if(this == &rh)
		{
			return *this;	
		}
		//清空原來的
		delete[] mem;
		mem = new T[rh.max];
		max = rh.max;
		len = rh.len;
		for(uint i = 0 ; i < rh.len ; i ++){
			mem[i] = rh.mem[i];
		}
		return *this;	
	}
};

int main(){
	Stack s1(4);
	Stack s2(s1);
	Stack s3(8);
	s1.push("1").push("3").push("5");
	s2.push("mizu").push("jun").push("tani").push("aran");
	s1.print();
	s2.print();
	s3 = s2;
	s3.print();

	return 0;
}




