/*
 * =====================================================================================
 *
 *       Filename:  zy_array.cpp
 *
 *    Description:  數組類定義
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 23时06分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "zy_array.h" 
#include "outofrange.h" 

Array::Array(int max){
	this->max = max;	
	cur = 0;
	pdata = new T[max];
	cout << "新建數組大小(" << max << ")：" << max*sizeof(T) << endl;
}

const int& Array::size()const{
	return cur;
}

ostream& operator <<(ostream& o,const Array& array){
	o << "[ " << array.pdata[0];
	for(int i = 1 ; i < array.cur; i ++){
		o << ',' << array.pdata[i]; 
	}
	o << " ]";
	return o;
}

istream& operator >>(istream& in,Array& array){
	cout << "準備輸入數據:" ;
	//char c;
	for(int i = 0 ; i < array.max ; i ++){
		/* 		in >> c;
		 * 		if(c == ';'){
		 * 			break;
		 * 		}
		 */
		in >> array.pdata[i];
		++array.cur;
	}
	cout << "數組有" << array.cur << "個數據，大小為" << array.max << endl;
	return in;
}

T& Array::operator [](int cur)const /* throw(ArrayException) */{
	if(cur >= max){
		throw ArrayException(cur,max);
	}
	return (pdata[cur]);
}

Array::~Array(){
	cout << "析構數組" << endl;
	delete[] pdata;
	pdata = NULL;
}









