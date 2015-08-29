/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  測試主函數
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 21时09分13秒
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
#include "binary.h" 

int main(){
	binary<int> b();
	b.insert(20);
	return 0;
}

