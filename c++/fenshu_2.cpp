/*
 * =====================================================================================
 *
 *       Filename:  fenshu.cpp
 *
 *    Description:  運算符重載
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

	void reduce(){
		int mcd = maxcd(n<0?-n:n,d);
		if(mcd != 1){
			n /= mcd;
			d /= mcd;
		}
	}

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
		reduce();	
	}

	//求最大公約數
	/*
	 *靜態類函數，不屬於任何一個對象，但屬於某個類
	 */
	static	int maxcd(int n,int d){
		if(n == 0){
			return d;
		}
		return maxcd((d % n),n);
	}

	friend ostream& operator<<(ostream& o,const F& f);
	friend F operator~(const F& f);
	bool operator!()const;

}; 

bool F::operator!()const{
	cout << *this << '(' << n*1.0/d << ')' << endl;
	return (n == 0);
}

F operator~(const F& f){
	return F (f.d,f.n);
}

ostream& operator<<(ostream& o,const F& f){
	o << f.n << "/" << f.d << "" ;
	return o;
}

int main(){
	F f1(4,6);
	cout << "--" << f1 << endl;
	//普通函數實現
	cout << "~~--" << ~f1 << endl;//operator~(f1);
	//成員函數實現
	cout << "!!--" << !f1 << endl;//f1.operator!();
	cout << "!!--" << !F(0,4) << endl;//f1.operator!();
	cout << "!!--" << !F(9,4) << endl;//f1.operator!();
	cout << "=================" << endl;
	!f1;
	cout << "---------"<< endl;
	!~f1;

	return 0;
}





