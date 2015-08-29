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
	List& push_front(const T& d){
		/* 		Node*p = new Node(d);	
		 * 		p->next = head;
		 * 		head = p;
		 */
		insert(d,0);
		return *this;
	}

	List& push_back(const T& data){
		insert(data,size());
		return *this;
	}

	//遍歷
	void travel()const{
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
	Node*& getptr(int pos){
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
	List& insert(const T& data,int pos){
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

	int size()const{
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
	List& erase(int pos){
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
	List& remove(const T& data){
		int pos ;
		while(( pos = find(data)) != -1){
			erase(pos);
		}
		return *this;
	}

	int find(const T& data)const{
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

	List& set(int pos,const T& data){
		if(pos < 0 || pos >= size()){
			return *this;
		}
		Node*& pn = getptr(pos);
		pn->data = data;
		return *this;
	}

	T front()const{
		if(empty()){
			throw "empty";
		}
		return head->data;
	}

	T back()const{
		if(empty()){
			throw "empty";
		}
		Node* p = head;
		while((p->next != NULL)){
			p = p->next;
		}
		return p->data;
	}

	bool empty()const{
		return head == NULL;
	}

	void clear(){
		while(head){
			Node* tmp = head->next;
			delete head;	
			head = tmp;
		}
	}

	~List(){ 
		clear();	
	}
};

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

