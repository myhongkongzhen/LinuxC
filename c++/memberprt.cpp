/*
 * =====================================================================================
 *
 *       Filename:  memberprt.cpp
 *
 *    Description:  成員指針
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 12时40分53秒
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

struct date{
	//相對地址，就是成員地址
	int year;//0
	int month;//4
	int day;//8
	void print(){
		cout << year << '-' << month << '-' << day << endl;
	}
};

//只輸出某個成員值
void showmember(date a[],int n,int date::*p){
	for(int i = 0 ; i < n ; i ++){
		//cout << a[i].*p << ' ' ;
		//cout << *(a+i).*p << ' ' ;
		cout << (a+i)->*p << ' ' ;
	}	
	cout << endl;
}

int main(){
	date a[3] = {{2011,4,5},{2012,6,8},{2000,1,2}};
	date d = {2014,3,3};
	cout << &d << endl;
	cout << &d.year << ' ' << &d.month << ' ' << &d.day << endl;
	cout << &date::year << '-' << &date::month << '-' << &date::day << endl;
	//cout << main << endl;

	//匿名聯合,不是個類型，直接變量聯合
	union{
		int n;
		//成員指針格式
		int date::*pm;
	};

	pm = &date::day;
	//顯示為8
	cout << n << endl;
	//可以直接訪問成員變量值
	cout << d.*pm << endl;
	pm = &date::month;
	cout << d.*pm << endl;
	pm = &date::year;
	cout << d.*pm << endl;

	showmember(a,3,&date::month);
	showmember(a,3,&date::year);
	showmember(a,3,&date::day);

	d.print();
	a[2].print();

	//成員函數指針
	void (date::*pf)() = &date::print;
	(d.*pf)();
	(a->*pf)();

	return 0;

}



