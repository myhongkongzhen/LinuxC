/*
 * =====================================================================================
 *
 *       Filename:  io.cpp
 *
 *    Description:  輸入輸出
 *					運算符重載operator>>
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 15时14分12秒
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

class F{
	int n;
	int d;
	public:
	F(int n = 0,int d = 1):n(n),d(d){}
	int getN()const{return n;}
	int getD()const{return d;}
	//友元函數
	//允許該外部函數訪問私有的變量
	friend istream& operator>>(istream& in,F& f);

};

istream& operator>>(istream& in,F& f){
	char c;
	in >> f.n >> c >> f.d;
	return in;
}
ostream& operator<<(ostream& out,const F& f){
	out << f.getN() << '/' << f.getD() ;
	return out;
}

int main(){
	/* 	F* f = new F(3,5);
	 * 	f->print();
	 * 	delete f;
	 */
	F a,b;
	cin >> a >> b; //cin.operator>>(a); operator>>(cin,a);
	cout << a << endl << b << endl;//cout.operator<<(a); operator<<(cout,a);
	return 0;
}




