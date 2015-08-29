/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  鏈錶測試主函數
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 11时26分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "zy_list.h" 

int main(){
	List l;
	l.insert(11).insert(45).insert(67,2).travel();
	l.insert(11,3).insert(23,2).insert(66,2).travel();
	l.remove(11).travel();
	l.insert(45).insert(33).insert(232).travel();
	l.remove(45).travel();
	l.edit(3,888).edit(2,999).travel();
	cout << l.get(2) << endl;
	cout << l.get(4) << endl;
	l.setEmpty();
	l.travel();
	l.insert(11,-1).insert(44,-4).insert(33,999).travel();;
	l.insert(3,44).insert(22,3).emas(2).travel();
	l.edit(12,888).travel();
	try{
		cout << l.get(4);
	}catch(const char* e){
		cout << e << endl;
	}
	return 0;
}

