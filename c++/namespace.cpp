/*
 * =====================================================================================
 *
 *       Filename:  namespace.cpp
 *
 *    Description:  自定義命名空間
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 09时09分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

namespace mizu{
	string name = "mizu";
}

namespace jun{
	string name = "jun";
}

//全局
string name = "tani";
int main(){
	cout << mizu::name << endl;
	cout << jun::name << endl;
	string name = "aran";
	cout << name << endl;

	//匿名命名空間，直接用雙冒號表示
	cout << ::name << "  全局範圍的name" << endl;
	return 0;
}



