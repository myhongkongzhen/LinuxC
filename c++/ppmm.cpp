/*
 * =====================================================================================
 *
 *       Filename:  fenshu.cpp
 *
 *    Description:  運算符重載
 *					單目運算符
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 16时44分18秒
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
	//private:
	int n;
	int d;

	public:
	F(int n = 0 , int d = 1):n(n),d(d){
		cout << "F(" << n << "/" << d << ")" << endl;
		if(d == 0){
			//			throw 0; //int
			throw "分母為0";//const char*
		}
		if(d < 0){
			this->d = -d;
			this->n = -n;
		}
	}

	friend ostream& operator<<(ostream& o,const F& f);

	F& operator++(){
		n += d;
		return *this;
	}
	F operator++(int){
		F old(*this);	
		n += d;
		return old;
	}
	friend F& operator--(F& f){
		f.n -= f.d;	
		return f; 
	}
	friend F operator--(F& f,int){
		F old(f);
		f.n -= f.d;	
		return old; 
	}
	//類型轉換運算，不寫返回類型
	operator double(){
		return 1.0*n / d;
	}
	operator bool(){
		return n ;
	}

}; 

ostream& operator<<(ostream& o,const F& f){
	o << f.n << "/" << f.d << "" ;
	return o;
}

void func1(F a){
	cout << a << endl;	
}

int main(){
	F f1(4,6);
	F f2(3,8);
	F f3(23,7);
	F f4(22,22);
	//++f1;//f1.operator++(); 
	//f2++;//f2.operator++(0);//多一個啞元參數，以示區別
	cout << "--f1-- " << ++f1 << endl;
	cout << "--f2-- " << f2++ << endl;
	cout << "--f2-- " << f2 << endl;
	//operator--(f3,0);
	cout << "--f3-- " << f3-- << endl;
	cout << "--f3-- " << f3 << endl;
	//operator--(f4);
	cout << "--f4-- " << --f4 << endl;
	cout << "--f4-- " << f4 << endl;

	//類型轉換運算符函數
	//f1.operator double();
	cout << double(f1) << endl;
	cout << (double)f2 << endl;
	//f3.operator bool();
	cout << bool(f3) << endl;
	cout << (bool)f4 << endl;

	//匿名對象,如果只有一個參數，可以看做是類型轉換
	cout << F(5) << endl;
	cout << (F)98 << endl;

	//自動轉換
	//F a(6) //實參初始化形參
	func1(6);
	return 0;
}





