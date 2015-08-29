/*
 * =====================================================================================
 *
 *       Filename:  1-03function.cpp
 *
 *    Description:  函數模板
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 00时17分01秒
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

template <typename T>
const T& Min(const T& a,const T& b){
	cout << "A--->" ;
	return a<b?a:b;
}

template <typename T>
T& Min(T& a,T& b){
	cout << "B--->" ;
	return a<b?a:b;
}

template <typename T,typename U>
T Min(const T& a,const U& b){
	cout << "C--->" ;
	return a<b?a:T(b);
}

const char* Min(const char*const& a,const char*const& b){ 
	cout << "D--->" ;
	return strcmp(a,b)?a:b; 
}

template <typename T>
T Min(const T& a,char b){ 
	cout << "E--->" ;
	return a<b?a:T(b);
}

template < >
const double& Min(const double& a,const double& b){ 
	cout << "F--->" ;
	return a<b?a:b;
}

int main(){
	cout << Min(20,10) << endl;
	cout << Min(2.4,3.5) << endl;
	cout << Min(5.9,6) << endl;
	//優先使用非模板函數
	cout << Min("tani","mizu") << endl;
	//指定使用模板函數
	cout << Min<>("tani","mizu") << endl;
	int m = 3,n = 5;
	double j = 4.5,k = 1.3;
	cout << Min(m,n) << endl;
	cout << Min(j,k) << endl;
	cout << Min(123,'x') << endl;
	return 0;
}

