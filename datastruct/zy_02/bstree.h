/*
 * =====================================================================================
 *
 *       Filename:  bstree.h
 *
 *    Description:   二叉查找樹頭文件
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 09时28分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef BSTREE_H
#define BSTREE_H 1

class bstree{
	struct Node{
		T data;		
		Node* left;
		Node* right;
		Node(const T& data = T()):data(data),left(),right(){}
		Node(const T& data ,Node*& left ,Node*& right):\
			data(data),left(left),right(right){}
	};
	Node* root;
	int cnt;
	public:
	bstree():cnt(0),root(){}
	//增，刪，改，查，遍歷，清空，printtree
	bstree& insert(Node*& tree,Node* node);
	bstree& insert(const T& data);
	bool remove(const T& data);
	bstree& edit(const T& odata,const T& ndata);
	Node*& find(Node*& tree,const T& data); 
	Node*& find(const T& data); 
	void travel(Node* tree)const;
	void travel()const;
	void clear(Node*& tree);
	void clear();
	const bool empty()const;
	int size()const;
	void printtree(Node*& tre,int space,char sign);
	void printtree();
	int height();
	int height(Node*& tree);
	~bstree();
};

#endif

