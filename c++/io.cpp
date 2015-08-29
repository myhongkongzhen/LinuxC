/*
 * =====================================================================================
 *
 *       Filename:  io.cpp
 *
 *    Description:  c++的io操作,input,output
 *					i.get(),o.put()
 *					i.getline(),i.ignore()  
 *					i.putback(),i.peek()
 *					.clear()清除錯誤狀態
 *					.eof(),.fail(),.bad(),.good()
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 18时49分20秒
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

//io對象要求能轉換成bool類型
//對正常狀態的io對象轉成true
//對錯誤狀態的io對象轉成false
int main(){
	cout << cin << endl;
	cout << cout << endl;
	int m;
	cin >> m;
	cout << cin << endl;
	if(cin){
		cout << "~~~~~~~~" << endl;
	}else{
		cout << "--error--" << endl;
	}

	cout << &cin << endl;
	cout << &cout << endl;

	//asiic
	int n = cin.get();//int get()
	char c,d;
	cin.get(c).get(d);//istream& get(char& ch)
	cout << n << ',';
	cout << c << ',';
	cout << d << endl;
	cout.put(n).put(c).put(d);
	cin.ignore(200,'\n');
	char l;
	cin >> l;
	cout << "--" << l << endl;
	/* 	cout << "hello" ;
	 * 	cerr << "world" ;
	 * 	clog << "tlll";
	 */
	return 0 ;
}

