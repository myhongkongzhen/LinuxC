/*
 * =====================================================================================
 *
 *       Filename:  bstree.cpp
 *
 *    Description:  二叉查找樹實現類
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 09时20分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <iomanip>
using namespace std;

typedef int T;
#include "bstree.h" 

bstree& bstree::insert(Node*& tree,Node* node){
	if(tree == NULL){
		tree = node;
		return *this;
	}
	if(tree->data > node->data){
		return insert(tree->left,node);
	}else{
		return insert(tree->right,node);
	}
}
bstree& bstree::insert(const T& data){
	++cnt;
	return insert(root,new Node(data));
}
bool bstree::remove(const T& data){
	Node*& fpn = find(data);
	if(fpn == NULL){
		return false;
	}

	Node* pn = fpn;
	if(fpn->left != NULL){
		insert(fpn->right,fpn->left);			
	}
	fpn = fpn->right;
	delete pn;
	pn = NULL;
	--cnt;
	return true;
}
bstree& bstree::edit(const T& odata,const T& ndata){
	Node*& fpn = find(odata);
	if(fpn == NULL){
		return *this;
	}

	fpn->data = ndata;
	return *this;
}
bstree::Node*& bstree::find(Node*& tree,const T& data){
	if(tree == NULL){
		return tree;
	}
	if(tree->data == data){
		return tree;
	}else if(tree->data > data){
		return find(tree->left,data);
	}else{
		return find(tree->right,data);
	}
}
bstree::Node*& bstree::find(const T& data){
	return find(root,data);
}
void bstree::travel(Node* tree)const{
	if(tree != NULL){
		travel(tree->left);
		cout << tree->data << ' ';
		travel(tree->right);
	}
}
void bstree::travel()const{
	travel(root);
	cout << endl;
}
void bstree::clear(Node*& tree){
	if(tree != NULL){
		clear(tree->left);
		clear(tree->right);
		delete tree;
		tree = NULL;
		--cnt;
	}
}
void bstree::clear(){
	clear(root);
}
const bool bstree::empty()const{
	return (cnt== 0);
}
int bstree::size()const{
	return cnt;
}
bstree::~bstree(){
	clear();
}
void bstree::printtree(Node*& tree,int space,char sign){
	if(tree == NULL){
		return;
	}
	printtree(tree->right,space+3,'/');
	cout << setw(space+1) << sign << tree->data << endl;
	printtree(tree->left,space+3,'\\');
}
void bstree::printtree(){
	printtree(root,0,'*');
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
int bstree::height(Node*& tree){
	if(tree == NULL){
		return 0;
	}

	int lh = height(tree->left);
	int rh = height(tree->right);
	return 1+(lh>rh?lh:rh);
}
int bstree::height(){
	return height(root);
}

/*
 * 按層次遍歷
 * 0、建立隊列
 * 1、根節點入隊列
 * 2、反復只要隊列長度>1
 *    2.1、取出一個節點
 *    2.2、訪問數據,判斷該指針是否為空	
 *		   2.2.1為空，打印換行
 *		   2.2.2非空，打印數據
 *    2.3、左右飛空子樹根節點入隊列
 *    2.4、插入一個NULL指針到隊列
 */

