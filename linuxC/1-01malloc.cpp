/*
 * =====================================================================================
 *
 *       Filename:  1-01malloc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 05时46分52秒
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
	int *p1 = new int;
	int *p2 = new int;
	int *p3 = new int;
	int *p4 = new int;
	int *p5 = new int;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;
	return 0;
}

