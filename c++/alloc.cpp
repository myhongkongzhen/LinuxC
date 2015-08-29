/*
 * =====================================================================================
 *
 *       Filename:  alloc.cpp
 *
 *    Description:  內存空間申請
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 12时06分13秒
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
#include <string>
#include <new>
using namespace std;

int main(){
	//c函數申請的空間，用free釋放，要配對
	string* p = static_cast<string*>(malloc(sizeof(string))) ;
	int* q = new int;
	int* r = new int(888);
	int n = 10;
	//動態數組沒有理由初始化，語法也不支持
	int* a = new(nothrow) int[n];
	if(a == NULL){
		cout << "new space error" << endl;
		return 1;
	}
	cout << *q << endl;
	cout << *r << endl;
	for(int i = 0 ; i < 10 ; i ++){
		cout << a[i] << " ";
		if(a[i]){
			cout << flush;
			char c;
			cin >> c;
		}
	}
	cout << endl;

	delete r;
	r = NULL;
	delete q;
	q = NULL;
	delete[] a;
	a = NULL;
	//delete p;//不能用delete來釋放
	free(p);
	p = NULL;

	return 0;
}


