/*
 * =====================================================================================
 *
 *       Filename:  3-03main.cpp
 *
 *    Description:  調用排序主函數
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 13时23分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <ctime>
using namespace std;

void sort(int* a,int n);

int main(){
	const int N = 10240;
	int a[N];
	for(int i = 0 ; i < N ; i ++){
		a[i] = N-i;
	}
	for(int i = 0 ; i < 10 ; i ++){
		cout << a[i] << ' ';
	}
	cout << endl;
	clock_t t1 = clock();
	sort(a,N);
	clock_t t2 = clock();
	cout << "排序耗時 ：" ;
	cout << ((t2 - t1)*1.0/CLOCKS_PER_SEC) << "s" << endl;
	for(int i = 0 ; i < 10 ; i ++){
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}

