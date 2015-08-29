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
#ifndef LINK_H
#define LINK_H 1

#include <iostream>
using namespace std;

class List{
	//內部類型而已，不是對象成員
	struct Node{
		T data;	
		Node* next;
		//---------------匿名初始化，稱為：零初始化
		//---------------基本類型，就是數值0，
		//---------------自定義類型就是建立一個無慘的匿名對象
		Node(const T& data = T()):data(data),next(NULL){}
	};
	//head不是個節點，是個頭指針
	//用來保存頭結點的地址
	Node* head;
	//元素個數，空間換時間
	int len;
	public:
	List():head(NULL),len(0){ }
	//在前面插入，前插
	List& push_front(const T& d);

	List& push_back(const T& data);

	//遍歷
	void travel()const;

	//找到指定位置的指針
	Node*& getptr(int pos);

	//在任意位置插入
	/* 	1.在鏈錶中找到指向那個位置的指針
	 * 	2.讓新節點的next指向找到的那個鏈錶中的指針指向同個地方
	 * 	3.讓找到的指針，指向新節點
	 */
	List& insert(const T& data,int pos);

	int size()const;

	//按位置刪除
	/* 1.找到鏈錶中指向那個位置的指針 
	 * 2.把這個指針另存一份
	 * 3.讓這個指針，指向下個節點
	 * 4.釋放那個節點的內存
	 * 5.--節點個數
	 */	
	List& erase(int pos);

	//按數據刪除
	List& remove(const T& data);

	int find(const T& data)const;

	List& set(int pos,const T& data);

	T front()const;

	T back()const;

	bool empty()const;

	void clear();

	~List();
};

#endif


