/*
 * =====================================================================================
 *
 *       Filename:  function.cpp
 *
 *    Description:  函數
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 13时22分32秒
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

void f1(){cout << "f1()" << endl; return;}
void f2(void){cout << "f2(void)" << endl; return;}

void f3(){return f1();}

//沒有名字的形參,用於新舊版本函數兼容
//有類型無名字形參，成為啞元
void f4(double){cout << "f4(double)" << endl;}

int main(){
	//無慘函數，與c不同，c是參數任意
	f1();
	f2();
	f3();
	//訪問不到34.5這個數據
	f4(34.5);
	return 0;	
}





