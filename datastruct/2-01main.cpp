/*
 * =====================================================================================
 *
 *       Filename:  1-02link.cpp
 *
 *    Description:  鏈錶
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 08时48分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
typedef int T;
#include "2-01link.h" 

int main(){
	List l;
	l.push_front(5);
	l.push_front(8);
	l.push_front(82);
	l.push_front(1098);
	l.travel();
	l.insert(34,3);
	l.travel();
	l.insert(134,-13);
	l.insert(134,13);
	l.insert(133334,113);
	l.insert(133334,3);
	l.travel();
	l.push_back(45);
	l.travel();
	l.insert(23,1).push_back(5).push_front(888).travel();
	l.erase(4).travel();
	l.erase(5).travel();
	l.remove(134).travel();
	l.remove(133334).travel();
	l.set(3,666666).travel();
	cout << l.find(8) << endl;
	l.set(l.find(8),99999).travel();
	cout << l.front() << "~~~~";
	cout << l.back() << endl;

	while(!l.empty()){
		l.erase(0);
	}
	cout << l.size() << endl;

	//cout << sizeof(l) << endl;
	return 0;
}

