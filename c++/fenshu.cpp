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

	friend F operator+(const F& lh,const F& rh);

	F operator*(const F& rh)const{
		/* 		F res(n*rh.n,d*rh.d);
		 * 		return res;
		 */
		//匿名對象
		return F(n*rh.n,d*rh.d);
	}

}; 

F operator+(const F& lh,const F& rh){
	/* 	F res(lh.n*rh.d+lh.d*rh.n,lh.d*rh.d);
	 * 	return res;
	 */
	//匿名對象
	return F(lh.n*rh.d+lh.d*rh.n,lh.d*rh.d);
}

ostream& operator<<(ostream& o,const F& f){
	o << f.n << "/" << f.d << "" ;
	return o;
}

int main(){
	F f(1);
	F f1(4,6);
	cout << "--------" << f+f1 << endl;

	F f3(14,36);
	//f+f1是個臨時值，要用引用，必須有const
	cout << "======" << f+f1+f3 << endl;
	cout << "--" << f3*f1 << endl;
	F f5(8972,-9026);
	cout << "f = " << f << ",f1=" << f1 << ",f3=" << f3 << ',' << f5 << endl;

	//通過類調用類函數
	cout << F::maxcd(3452,67532) << endl;
	/* 	F f2(1,0);
	 * 	cout << f2 << endl;
	 */
	return 0;
}





