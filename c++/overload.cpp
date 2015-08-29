/*
 * =====================================================================================
 *
 *       Filename:  overload.cpp
 *
 *    Description:  函數重載的實現
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 08时39分49秒
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

/*
 * 讓編譯器不改變函數名字
 * 讓函數像C語言那樣使用，可以被外部程序應用
 * 但如果全部都不改變名字，就失去了C++的重載的意義了
 */
extern "C" void print(int a[],int n){
	for(int i = 0 ; i < n ; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

void print(int a[],int n,char c){
	for(int i = 0 ; i < n ; i++){
		cout << a[i] ;
		if(i != n - 1)
			cout << c;
	}
	cout << endl;
}

void print(int a[],int n,bool b){
	if(b){
		cout << '[';
	}
	for(int i = 0 ; i < n ; i++){
		cout << a[i] << ' ';
	}
	cout << '\b';
	if(b){
		cout << ']';
	}
	cout << endl;
}

int main(){
	int a[3] = {11,22,33};
	print(a,3);
	print(a,3,',');
	print(a,3,true);
	return 0;
}





