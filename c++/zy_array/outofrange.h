/*
 * =====================================================================================
 *
 *       Filename:  outofrange.h
 *
 *    Description:   自定義異常類頭文件
 *
 *        Version:  1.0
 *        Created:  2014年08月02日 01时10分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef OUTOFRANGE_HEADER_1
#define OUTOFRANGE_HEADER_1 1

#include <iostream>
using namespace std;

class ArrayException : public exception{
	char msg[200];
	public :
	ArrayException(int cur,int max);
	const char* what()const throw();
};

#endif

