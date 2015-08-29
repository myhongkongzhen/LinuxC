/*
 * =====================================================================================
 *
 *       Filename:  polymorphis.cpp
 *
 *    Description:  多態,純虛函數，抽象類
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 14时20分57秒
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

//抽象類,有純虛函數的類
//不允許創建抽象類的對象，
//但可以使用抽象類的指針和引用，指向子類對象
class Animal{
	public:
		//構造和析構函數中，不會調用虛函數，只調用本類函數
		Animal(){
			//sleep();
		}
		//虛析構函數
		//析構函數一定不能是純虛析構函數
		virtual ~Animal(){
			//shout();	
		}
		void play(){
			//自動調用虛函數
			eat();
			shout();
			sleep();
		}
		/* 
		 * 		virtual	void eat(){
		 * 			cout << "---eat---" << endl;	   
		 * 		}
		 * 		virtual void shout(){
		 * 		cout << "~~~Animal--shout~~~" << endl;	   
		 * 		}
		 * 		virtual void sleep(){
		 * 			cout << "---Animal--sleep--" << endl;
		 * 		}
		 */
		//純虛函數,保證由子類來實現
		//接口
		virtual void eat() = 0;
		virtual void shout() = 0;
		virtual void sleep() = 0;
};

class Horse:public Animal{
	public:
		Horse(){
			cout << "Horse" << endl;	
		}
		~Horse(){
			cout << "~Horse" << endl;	
		}
		virtual	void eat(){
			cout << "Horse eat()" << endl;	   
		}
		virtual void shout(){ 
			cout << "Horse shout()" << endl;	   
		}
		virtual void sleep(){
			cout << "Horse sleep()" << endl;	   
		}
};

class Tiger:public Animal{
	public:
		Tiger(){
			cout << "Tiger" << endl;	
		}
		~Tiger(){
			cout << "~Tiger" << endl;	
		}
		virtual	void eat(){
			cout << "Tiger eat()" << endl;	   
		}
		virtual void shout(){ 
			cout << "Tiger shout()" << endl;	   
		}
		virtual void sleep(){
			cout << "Tiger sleep()" << endl;	   
		}
};

int main(){
	Animal* p = NULL;
	char choice;
	cout << "please input choice --> h:Horse,t:Tiger" << endl;
	cin >> choice;
	if(choice == 'h'){
		p = new Horse;	
	}else{
		p = new Tiger;	
	}

	p->play();
	cout << "--------------------" << endl;
	//p->Animal::eat();

	delete p;
	p = NULL;

	return 0;
}




