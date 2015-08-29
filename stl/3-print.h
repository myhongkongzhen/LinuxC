/*
 * =====================================================================================
 *
 *       Filename:  print.h
 *
 *    Description:  輸出頭文件
 *
 *        Version:  1.0
 *        Created:  2014年08月08日 23时54分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef PRINT_H
#define PRINT_H 1	

template <typename T>
void print(T b,T e,char c = ' '){
	cout << *b++ ;
	while(b != e){
		cout << c << *b++ ;
	}
	cout << endl;
}

template < typename K,typename V >
ostream& operator << (ostream& o, const pair<K,V>& p){
	return o << p.first << ':' << p.second ;
}

#endif

