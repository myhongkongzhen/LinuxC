/*
 * =====================================================================================
 *
 *       Filename:  destructor.cpp
 *
 *    Description:  析構函數
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 13时23分32秒
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
	//默認構造函數
	F(int n = 444 ,int d = 1);
	//拷貝構造函數
	//如果沒有寫出來，編譯器會自動產生一個拷貝構造函數
	//完成所有成員的逐個複製
	F(const F& f):n(f.n-1),d(f.d+1){
		cout << this << "  -- F(const F& f)" << n << "/" << d << endl;
	}

	//重載

	//編譯器優先使用自由的這個
	void print(bool newLine = true);
	//此函數對當前對象操作是只讀的
	//不夠自由
	void print(bool newLine = true)const;

	void input();
	~F();
};

//不夠自由
void F::print(bool newLine)const{
	cout << " const -- " ;
	cout << n << "/" << d ; 
	if(newLine){
		cout << endl;
	}
}
F::F(int n,int d):n(n),d(d){
	//this是本對象的地址
	cout << this << " == F(" << n << "," << d << ")" << endl;
}
//析構函數
F::~F(){
	cout << this << "  == ~F(" << n << "," << d << ")" << endl;
}
void F::print(bool newLine){
	cout << " -- " ;
	cout << n << "/" << d ; 
	if(newLine){
		cout << endl;
	}
}
void F::input(){

}

int compare(const F& x,const F& y){
	x.print();
	y.print();
	return 0;
}

//調用的是拷貝構造函數
F func(F x){
	return x;
}

int main(){

	F f(3,5);
	cout << "=============" << endl;
	func(f);
	cout << "=============" << endl;

	/* 
	 * 不建議在C++中使用Xalloc來申請內存空間
	 * //不會調用構造函數
	 * 	F* q = static_cast<F*>(malloc(sizeof(F)));
	 * 	//不會調用析構函數
	 * 	free(q);
	 */

	F* p = new F;
	F a(1,2),b(3,4);
	b.print();
	a.print(false);
	delete p;
	p = NULL;

	//創建對象，堆中申請內存空間
	F* q = new F[2];
	for(int i = 0 ; i < 4 ; i ++){
		q[i].print();
	}
	//釋放數組
	delete[] q;
	q = NULL;

	p = new F(8);
	p->print();
	delete p;
	p = NULL;

	const F c(33,555);
	//const變量只能調用const的函數
	//c.input();//這是錯誤的	
	//此時調用的是const的，不自由的
	c.print();

	cout << "-----------------------" << endl;
	compare(a,b);
	cout << "-----------------------" << endl;

	return 0;
}



