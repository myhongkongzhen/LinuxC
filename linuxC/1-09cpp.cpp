/*
 * =====================================================================================
 *
 *       Filename:  1-09cpp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 08时59分02秒
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

//windows下直接這樣使用
//int __cdecl add(int a,int b){
int __attribute__((__cdecl))add(int a,int b){
	return a+b;
}

int main(){

	return 0;
}

