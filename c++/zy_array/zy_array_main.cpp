/*
 * =====================================================================================
 *
 *       Filename:  zy_array_main.cpp
 *
 *    Description:  主函數
 *
 *        Version:  1.0
 *        Created:  2014年08月02日 00时35分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "zy_array.h" 

int main(){
	try{
		int n;
		cout << "輸入數組個數:" ;
		cin >> n;
		Array a(n);
		cin >> a;
		cout << a << endl;

		cout << "輸入數組下標:" << endl;
		cin >> n;
		cout << "該值為：" << a[n] << endl;

		cout << "數組大小為：" << a.size() << endl;
	}catch(ArrayException e){
		cout << e.what() << endl;
	}catch(exception e){
		cout << e.what() << endl;
	}

	return 0;
}

