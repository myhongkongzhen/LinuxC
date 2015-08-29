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
#include <iostream>
using namespace std;
typedef int T;
#include "2-01link.h" 

//在前面插入，前插
List& List::push_front(const T& d){
	/* 		Node*p = new Node(d);	
	 * 		p->next = head;
	 * 		head = p;
	 */
	insert(d,0);
	return *this;
}

List& List::push_back(const T& data){
	insert(data,size());
	return *this;
}

//遍歷
void List::travel()const{
	Node* p = head;	
	while(p != NULL){
		cout << p->data << ' ';
		p = p->next;
		if(p == head){
			break;
		}
	}
	cout << endl;
}

//找到指定位置的指針
List::Node*& List::getptr(int pos){
	if(pos == 0){
		return head;
	}
	Node* p = head;
	for(int i = 1 ; i < pos ; i ++){
		p = p->next;
	}
	return p->next;
}

//在任意位置插入
/* 	1.在鏈錶中找到指向那個位置的指針
 * 	2.讓新節點的next指向找到的那個鏈錶中的指針指向同個地方
 * 	3.讓找到的指針，指向新節點
 */
List& List::insert(const T& data,int pos){
	if(pos < 0){
		pos = 0;
	}
	if(pos > size()){
		pos = size();
	}
	//找到指定位置的指針
	Node*& pn = getptr(pos);
	Node* p = new Node(data);
	p->next = pn; 
	pn = p;
	++len;
	return *this;
}

int List::size()const{
	//元素個數，空間換時間
	/* 		int cnt = 0;
	 * 		Node* p = head;	
	 * 		while(p != NULL){
	 * 			p = p->next;
	 * 			++cnt;
	 * 		}
	 * 		return cnt;
	 */
	return len;
}

//按位置刪除
/* 1.找到鏈錶中指向那個位置的指針 
 * 2.把這個指針另存一份
 * 3.讓這個指針，指向下個節點
 * 4.釋放那個節點的內存
 * 5.--節點個數
 */	
List& List::erase(int pos){
	if(pos >=0 && pos < size()){
		Node*& pn = getptr(pos);
		Node* tmp = pn;
		pn = pn->next;
		delete tmp;
		--len;
	}
	return *this;
}

//按數據刪除
List& List::remove(const T& data){
	int pos ;
	while(( pos = find(data)) != -1){
		erase(pos);
	}
	return *this;
}

int List::find(const T& data)const{
	int pos = 0;
	Node* p = head;
	while(p){
		if(p->data == data){
			return pos;
		}
		p = p->next ;
		++pos;
	}
	return -1;
}

List& List::set(int pos,const T& data){
	if(pos < 0 || pos >= size()){
		return *this;
	}
	Node*& pn = getptr(pos);
	pn->data = data;
	return *this;
}

T List::front()const{
	if(empty()){
		throw "empty";
	}
	return head->data;
}

T List::back()const{
	if(empty()){
		throw "empty";
	}
	Node* p = head;
	while((p->next != NULL)){
		p = p->next;
	}
	return p->data;
}

bool List::empty()const{
	return head == NULL;
}

void List::clear(){
	while(head){
		Node* tmp = head->next;
		delete head;	
		head = tmp;
	}
}

List::~List(){ 
	clear();	
}


