/*
 * =====================================================================================
 *
 *       Filename:  zy_array.h
 *
 *    Description:   數組類頭文件
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 23时06分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef ZY_ARRAY_
#define ZY_ARRAY_ 1

#include <iostream>
#include <exception>
#include "outofrange.h" 
using namespace std;

typedef int T;

class Array{
	T* pdata;	
	int max;
	int cur;                      
	public:
	Array(int max);
	//size()
	const int& size()const;
	//[],<<,>>
	friend ostream& operator <<(ostream& o,const Array& array);
	friend istream& operator >>(istream& i,Array& array);
	T& operator [](int cur)const /* throw(ArrayException) */;
	~Array();
};

#endif

