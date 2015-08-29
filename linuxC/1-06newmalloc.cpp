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
using namespace std;

int main(){

	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int));
	int* p4 = new int;
	int* p5 = new int;
	int* p6 = new int;

	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p3 = " << p3 << endl;
	cout << "p4 = " << p4 << endl;
	cout << "p5 = " << p5 << endl;
	cout << "p6 = " << p6 << endl;

	delete p6;
	delete p5;
	delete p6;
	free(p3);
	free(p2);
	free(p1);

	//printf("%d\n",getpid());
	//while(1);

	return 0;
}

