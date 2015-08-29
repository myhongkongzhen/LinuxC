/*
 * =====================================================================================
 *
 *       Filename:  class.cpp
 *
 *    Description:  自定義類型
 *
 *        Version:  1.0
 *        Created:  2014年07月29日 20时41分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "class.h"

//外部的類成員函數定義
PC::PC(const char* name,int a){
	//可以指定哪個域中的變量名
	PC::name = name;	
	age = a;
}

void PC::show(){
	cout << name << "====" << age << endl;
}








