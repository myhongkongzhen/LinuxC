/*
 * =====================================================================================
 *
 *       Filename:  binary.cpp
 *
 *    Description:  二叉樹模板
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 20时27分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef BINARY_H
#define BINARY_H 1

#include <iostream>
using namespace std;

template <typename T>
class binary{
	struct Node{
		T data;		
		Node* left;
		Node* right;
		Node(const T& data = T()):data(data),left(),right(){}
		Node(const T& data,Node* left,Node* right):\
			data(data),left(left),right(right){}
	};
	Node* root;
	int cur;
	public:
	binary():root(),cur(){ }
	//增刪改查，清空，遍歷
	binary& insert(Node*& tree,Node* node){
		++cur;
		if(tree == NULL){
			tree = node;
		}	
		if(node->data < tree->data){
			insert(tree->left,node);
		}
		insert(tree->right,node);
		return *this;
	}	
	binary& insert(const T& data){
		return insert(root,new Node(data));
	}
	Node*& find(Node*& tree,const T& data)const{
		if(tree == NULL){
			return tree;
		}else if(tree->data == data){
			return tree;
		}else if(data < tree->data){
			return find(tree->left,data);
		}else {
			return find(tree->right,data);
		}
	}
	Node*& find(const T& data){
		return find(root,data);
	}
	bool remove(Node*& tree,T& data){
		--cur;
		if(tree == NULL){
			return false;
		}
		Node*& fp = find(tree,data);
		if(fp == NULL){
			return false; 
		}
		Node* tmp = fp;
		if(fp->left != NULL){
			insert(fp->right,fp->left);
		}
		fp = fp->right;
		delete tmp;
		tmp = NULL;
		return true;
	}
	bool remove(T& data){
		return remove(root,data);
	}
	binary& edit(T& odata,T& ndata){
		if(remove(odata)){
			return insert(ndata);
		}
		return *this; 
	}
	void clear(Node*& tree){
		if(tree == NULL){
			return;
		}	
		clear(tree->left);
		clear(tree->right);
		delete tree;
		tree = NULL;
		cur = 0;
	}
	void clear(){
		clear(root);
	}
	void travel(const Node*& tree)const{
		if(tree == NULL){
			return;
		}
		travel(tree->left);
		cout << tree->data << ' ';
		travel(tree->right);
	}
	void travel()const{
		travel(root);
		cout << endl;
	}
	bool empty()const{
		return (cur == 0);
	}
	int size()const{
		return cur;
	}
	~binary(){clear();}
}; 

#endif

