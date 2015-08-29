/*
 * =====================================================================================
 *
 *       Filename:  funcop.cpp
 *
 *    Description:  運算符重載
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 22时08分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring> // c中的string.h
using namespace std;

class A{
	public:
		typedef unsigned int uint;
	private:
		int* p;
		uint n;
	public:
		A(uint n):n(n){
			p = new int[n];
			if(p == NULL){
				throw 0;
			}
			memset(p,0,n*sizeof(uint));
		}
		~A(){
			delete[] p;
		}
		int& operator[](uint i)const{
			if(i>=n)
				throw 1;
			return p[i];
		}
		int& operator[](const char* c)const{
			int i = atoi(c);
			if(i < 0 || i >= n)
				throw 1;
			return p[i];
		}
		uint size()const{
			return n;
		}
		void operator()(int v){
			for(uint i = 0 ; i < n ; i ++){
				p[i] = v;
			}
		}
		void operator()(const char* s){
			int v = atoi(s);
			for(uint i = 0 ; i < n ; i ++){
				p[i] += v;
			}
		}
		int operator()(int beg,int delta){
			for(uint i = 0 ; i < n ;  i++){
				p[i] = beg;
				beg += delta;
			}
			return p[n-1];
		}

};

//操作與對象成員數據無關，可定義為非成員函數
ostream& operator<<(ostream& o,const A& a){
	o << "{ "; 
	for(unsigned int i = 0 ; i < a.size() ; i ++){
		o << a[i] <<  " ";
	}
	o << '}'; 
	return o;
}

int main(){
	A x(5),y(8);
	//x.operator[](2);
	x[2] = 20;
	//y.operator[](6);
	y[6] = 66;
	x["0"] = 99;
	y["4"] = 23;
	cout << x << endl;
	cout << y << endl;
	x(3);//x.operator()(3);
	cout << x << endl;
	y("40");
	cout << y << endl;
	//x.operator()(10,2)
	//函數對象
	cout << x(10,2) << endl;
	cout << x << endl;
	cout << y(50,-1) << endl;
	cout << y << endl;

	return 0;
}





