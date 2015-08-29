/*
 * =====================================================================================
 *
 *       Filename:  2-05deque.cpp
 *
 *    Description:  雙端隊列個性
 *
 *        Version:  1.0
 *        Created:  2014年08月09日 21时59分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <deque>
#include <exception>
#include <typeinfo>
using namespace std;
#include "print.h"

int main(){
	deque<char> dc;
	dc.push_back('e');
	dc.push_back(97);
	dc.push_back('b');
	dc.push_front(45);
	dc.push_front('m');
	dc.push_front('l');
	print(dc.begin(),dc.end(),',');
	dc[3] = 'H';
	print(dc.begin(),dc.end(),',');
	try{
		dc.at(8) = 'K';
		print(dc.begin(),dc.end(),',');
	}catch(exception e){
		cout << e.what() << endl;
		cout << typeid(e).name()<< endl;
	}
	dc.pop_back();
	dc.pop_front();
	print(dc.begin(),dc.end(),',');
	return 0;
}

