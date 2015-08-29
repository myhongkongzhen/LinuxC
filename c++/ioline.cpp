/*
 * =====================================================================================
 *
 *       Filename:  ioline.cpp
 *
 *    Description:  讀取一行,都可有第三個參數，指定結束符
 *					默認為換行
 *					i.getline(char[],size)
 *					getlnie(istream,string&) √
 *					i.putback(char)
 *					i.peek();
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 20时00分47秒
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

int main(){
	char buf[10];
	//if(!cin.getline(buf,sizeof(buf))){
	if(!cin.getline(buf,sizeof(buf),'~')){
		cout << "==ERROR==" << endl;	
		cin.clear();
		cin.ignore(1000,'\n');
	}
	cin >> ws;
	cout << buf << endl;
	cout << "=================" << endl;
	string str;
	//getline(cin,str);
	//可指定結束符
	getline(cin,str,';');
	cout << str << endl;
	char c = cin.get();
	cin.putback(c);
	//跳過空白字符
	cin >> ws;
	return 0 ;
}

