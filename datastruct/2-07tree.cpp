/*
 * =====================================================================================
 *
 *       Filename:  2-07tree.cpp
 *
 *    Description:  二叉樹
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 20时57分10秒
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

class bst{
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(const T& data = T()):\
			data(data),left(),right(0){}
		//data(data),left(0),right(NULL){}
		Node(const T& data,Node* left,Node* right):\
			data(data),left(left),right(right){}
	};
	typedef Node* tree;
	//根節點指針
	Node* root;
	int cnt;
	public:
	//零初始化，0可以不寫
	bst():root(),cnt(){}
	bst& insert(tree& t,Node* p); 
	tree& find(tree& t,const T& data)const;
	void travel(const tree& t)const;
	void clear(tree& t);
	int height(tree& t)const;
	int height();
	bst& insert(const T& data);
	tree& find(const T& data);
	void travel()const;
	bool empty()const;
	int size()const;
	bst& remove(const T& dat);
	void clear();
	const T& getroot()const;
	bst& update(const T& odata,const T& ndata);
	~bst(){
		clear();
	}
};

bst& bst::update(const T& odata,const T& ndata){
	return remove(odata).insert(ndata);
}

const T& bst::getroot()const{
	if(!root){
		throw "empty";
	}
	return root->data;
}

int bst::height(){
	return height(root);
}

bst::bst& bst::remove(const T& data){
	tree& fp = find(data);	
	if(fp == NULL){
		return *this;
	}
	tree tmp = fp;
	if(fp->left){
		insert(fp->right,fp->left);
	}
	fp = fp->right;
	delete tmp;
	tmp = NULL;
	--cnt;
	return *this;
}

int bst::size()const{
	return cnt;
}

bool bst::empty()const{
	return (cnt == 0);
}

void bst::travel()const{
	travel(root);
	cout << endl;
}

bst::tree& bst::find(const T& data){
	return find(root,data);
}

bst& bst::insert(const T& data){
	++cnt;
	return insert(root,new Node(data));
}

void bst::clear(){
	clear(root);
	cnt = 0;
}

int max(int& m,int& n){
	return (m>n?m:n);	
}

int bst::height(tree& t)const{
	if(t == NULL){
		return 0;
	}
	int lh = height(t->left);	
	int rh = height(t->right);	
	return 1+max(lh,rh);
}

void bst::clear(tree& t){
	if(t == NULL){
		return ;
	}
	clear(t->left);
	clear(t->right);
	delete t;
	t = NULL;
}

void bst::travel(const tree& t)const{
	if(t == NULL){
		return;
	}

	travel(t->left);
	cout << t->data << ' ';
	travel(t->right);
}

bst::tree& bst::find(tree& t,const T& data)const{
	if(t == NULL){//沒找到
		return t;
	}else if(data == t->data){ //找到了
		return t; 
	}else if(data < t->data){
		return find(t->left,data);
	}else{
		return find(t->right,data);
	}
}

bst& bst::insert(tree& t,Node* p) {
	if(t == NULL){
		t = p;
	}else if(p->data < t->data){
		insert(t->left,p);	
	}else{
		insert(t->right,p);
	}
	return *this;
}

int main(){
	bst b;
	b.insert(44).insert(5).insert(8).travel();
	b.insert(14).insert(53).insert(88).travel();
	b.insert(214).insert(13).insert(9).travel();
	b.remove(214).travel();
	b.remove(53).remove(5).travel();
	cout <<	b.height() << endl;
	cout << b.size() << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;
	b.travel();
	b.update(44,1).travel();
	cout << "~~~~~~~~~~~~~~~" << endl;
	while(!b.empty()){
		cout << b.getroot() << ' ';
		b.remove(b.getroot());
	}
	cout << endl << b.size() << endl;
	b.travel();

	return 0;
}


