/*
 * =====================================================================================
 *
 *       Filename:  const.cpp
 *
 *    Description:  const
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 14时45分07秒
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

class Array{
	char a[100];
	int len;
	//情理上不可以改變，代碼上可以改變
	mutable int cur;
	public:
	Array():len(0){}
	//理論上取第一個值，不需要改變對象，但實際上，下標需要改變
	void first()const{cur = -1;}
	char next()const{return a[++cur];}
	bool hasnext()const{return (cur<len-1);}
	void add(char c);
	void add(const char* s){
		while(*s){
			add(*s++);
		}
	}
	void remove(int pos);
};

void Array::add(char c){ a[len++] = c; }
void Array::remove(int pos){
	if(pos < 0){
		pos = 0;
	}else if(pos >= len){
		pos = len - 1;	
	}
	while(pos<len){
		a[pos] = a[pos+1];
		++pos;
	}
	--len;
}

/* main方法中即使不寫任何代碼，也會執行，全局變量會被初始化 */
/*  
	int func(){
	cout << "全局函數被調用" << endl;return 1;
	}
	int x = func();
	class X{
	public:
	X(){cout << "x()" << endl;}
	~X(){cout << "~x()" << endl;}
	};
	X y;
	*/

void show(Array& a){
	a.first();
	while(a.hasnext()){
		cout << a.next() << ' '; 
	}
	cout << endl;
}
int main(){
	Array a;
	a.add('h');
	a.add("ellow");
	a.add(" world!");

	show(a);

	return 0;
}




