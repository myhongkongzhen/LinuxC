/*
 * =====================================================================================
 *
 *       Filename:  zy_list.h
 *
 *    Description:  鏈錶頭文件
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 11时20分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef ZY_LIST_
#define ZY_LIST_ 1

#include <iostream>
using namespace std;

class List{
	struct Node{
		T data;	
		Node* next;
		Node(const T& data = T()):data(data),next(NULL){}
	};
	Node* head;
	int len;
	public:
	List();
	//增刪改查，遍歷，清空，倒置，排序，合併
	List& insert(const T& data,int pos = 0);
	List& remove(const T& data);
	List& emas(int pos);
	List& edit(int pos,const T& data);
	T get(int pos);
	void travel();
	Node*& getptr(int pos);
	int size();
	int getdata(const T& data);
	bool empty();
	void setEmpty();
	void clear();
	~List();
};

#endif

