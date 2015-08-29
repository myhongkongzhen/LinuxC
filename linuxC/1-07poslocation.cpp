/*
 * =====================================================================================
 *
 *       Filename:  1-03varmem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 06时20分40秒
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
#include <new>
using namespace std;

int main(){

	char a[20];
	//定位分配,對應realloc
	int* p = new(a) int;
	cout << p << endl;

	//printf("%d\n",getpid());
	//while(1);

	return 0;
}

