/*
 * =====================================================================================
 *
 *       Filename:  node.cpp
 *
 *    Description:  節點
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 08时06分24秒
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

typedef int T;

//結構里同樣可以有構造函數，析構函數等一系列函數，同class類中
//只是結構里的默認都是公開的，class類中的默認是private的
struct Node {
	T data;
	Node* next;
	Node(const T& data):data(data),next(NULL){ }
	//類型轉化，轉成T類型數據輸出
	operator T(){
		return data;
	}
};

void showlist(Node* head){
	Node* p = head;
	while( p != NULL){
		cout << *p << ' ';  
		p = p->next;
		//p = (*p).next;
		//循環
		if( p == head ){
			break;
		}	
	}
	cout << endl;
}

int main(){
	Node a(10),b(20),c(30),d(40);
	cout << a << '-' << b << endl;
	a.next = &b;	
	b.next = &c;	
	c.next = &d;	
	showlist(&a);

	//p是b.next的引用，p是一個Node*指針
	Node*& p = b.next; 
	Node e(25);
	//e.next = b.next;
	e.next = p;
	p = &e;
	showlist(&a);

	Node* k = new Node(35);
	k->next = c.next;
	c.next = k;
	showlist(&a);

	delete k;

	return 0;
}

