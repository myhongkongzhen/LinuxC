/*
 * =====================================================================================
 *
 *       Filename:  format.cpp
 *
 *    Description:  格式控制
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 09时20分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//---跳過空白---16-----10-----8
	//格式控制符
	//cin >> ws >> hex >> dec >> oct
	cout.width(10);
	cout << 123 << ',' << 3423 << endl;
	cout.width(2);
	//--------------------iomanip--
	cout << 123 << ',' << setw(8) << 3423 << endl;
	cout << hex << 99 << '-' << 47 << endl;
	//函數形式設置
	cout.setf(ios::hex,ios::basefield);//oct,dec,showbase
	cout << showbase << 124 << endl;
	cout << 123 << endl;
	//取消標誌
	cout.unsetf(ios::hex);//oct,dec,showbase
	cout << 123 << endl;
	cout << 5.0 << endl;
	cout << showpoint <<  5.0 << endl;
	//------科學計數法
	cout << scientific << 9.9 << endl;
	//精度
	cout.precision(3);
	//科學計數法中表示小數點的位數
	cout << 4.3 << endl;
	cout.unsetf(ios::scientific);
	//普通計數法中表示有效位數
	cout << 4.3 << endl;
	cout << fixed << 4.3 << endl;
	cout << setprecision(2) << 4000.0 << endl;
	cout << showpos << 54 << endl;
	cout << 34 << endl;
	cout << showpos << -154 << endl;
	cout << uppercase << hex << scientific << 34.5 << endl;
	cout.fill('~');
	cout << setw(10) << dec << 123 << endl;
	cout << setw(10) << left << 123 << '-' << 44 << endl;
	cout << setw(10) << setfill('!') << left << 123 << endl;
	//------兩側對齊
	cout << internal << setw(10)<< 123 << endl;
	return 0;
}

