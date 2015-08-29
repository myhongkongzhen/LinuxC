/*
 * =====================================================================================
 *
 *       Filename:  cast.cpp
 *
 *    Description:  類型轉換算子
 *					static_cast      數值類型之間，有一方void*的指針類型只見到轉換 ,
 *								     這是合理的轉換
 *					const_cast       臨時用於去掉const,volatile限制
 *					reinterpret_cast 用於任意兩種指針類型之間,指針數值類型之間的轉換,
 *									 最危險的一種類型轉換 
 *					dynamic_cast     用於父子類之間的轉換
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 11时11分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int n = static_cast<int>(32.2);
	cout << n << endl;
	int* p = static_cast<int*>(calloc(sizeof(int),10));
	cout << p << endl;
	free(p);

	//const int m = 100;
	const int m = n;
	cout << m << endl;
	const_cast<int&>(m) = 44446;
	cout << m << endl;

	float f = 343.5;
	p = reinterpret_cast<int*>(&f);
	cout << *p << endl;

	//把類型名當成一個函數一樣
	n = int(45.45);
	cout << n << endl;
	//空表示0
	n = int();
	cout << n << endl;

	//初始化值放到括號中
	int x(200);
	cout << x << endl;

	int(y) = 9;
	cout << y << endl;

	return 0;
}



