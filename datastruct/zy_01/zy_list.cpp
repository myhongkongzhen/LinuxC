/*
 * =====================================================================================
 *
 *       Filename:  zy_list.c
 *
 *    Description:   鏈錶實現
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 11时22分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
typedef int T;
#include "zy_list.h" 

List::List(){
	head = NULL;
	len = 0;
}

void List::clear(){
	while(head){
		Node* p = head->next;
		delete head;
		head = p;
	}
}

List::~List(){
	clear();
}

List& List::insert(const T& data,int pos){
	if(pos < 0 ){
		pos = 0;
	}
	if(pos > len){
		pos = len;
	}
	Node*& pn = getptr(pos);
	Node* p = new Node(data);
	p->next = pn;
	pn = p;
	++len;
	return *this;
}

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

List& List::remove(const T& data){
	int pos ;
	while((pos = getdata(data)) != -1){
		emas(pos);
	}
	return *this;
}

List& List::emas(int pos){
	if(pos < 0 || pos >= len){
		return *this;
	}
	Node*& pn = getptr(pos);
	Node* p = pn;
	pn = pn->next;
	delete p;
	--len;
	return *this;
}

int List::getdata(const T& data){
	Node* pn = head;
	int pos = 0;
	while(pn){
		if((pn->data == data)){
			return pos;
			break;
		}
		++pos;
		pn = pn->next;
	}
	return -1;
}

List& List::edit(int pos,const T& data){
	if(pos < 0 || pos >= len){
		return *this;
	}
	Node*& pn = getptr(pos);
	pn->data = data;
	return *this;
}

int List::size(){
	return len;
}

T List::get(int pos){
	if(pos< 0 || pos >= len){
		throw "error";
	}
	return ((getptr(pos))->data);
}

void List::travel(){
	cout << "共有" << len << "個元素!" << endl;
	Node* p = head;
	while(p){
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

bool List::empty(){
	return (len == 0);
}

void List::setEmpty(){
	while(!empty()){
		emas(0);
	}
}


