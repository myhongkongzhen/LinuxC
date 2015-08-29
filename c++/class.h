/*
 * =====================================================================================
 *
 *       Filename:  class.cpp
 *
 *    Description:  自定義類型
 *
 *        Version:  1.0
 *        Created:  2014年07月29日 20时41分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef CLASS_H
#define CLASS_H 1

#include <string>
using namespace std;

//默認是私有的數據
//公開訪問數據的函數
class PC{
	string name;
	int age;

	public:
	//構造函數
	PC(const char* name,int a);

	void show();

};

#endif




