/*
 * =====================================================================================
 *
 *       Filename:  bool.cpp
 *
 *    Description:  布爾類型
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 10时26分05秒
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

int main(){
	bool g = true;
	bool s = false;
	cout << (!g?"ll":"hh") << endl;
	cout << s << '-' << g << endl;
	//配置bool類型用字母輸出
	cout << boolalpha << s << '-' << g << endl;
	return 0;
}



