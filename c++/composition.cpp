/*
 * =====================================================================================
 *
 *       Filename:  mul_inheriance.cpp
 *
 *    Description:  多重繼承,組合
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 10时07分31秒
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

class Goods{
	double price;
	public:
	Goods(double price = 300):price(price){
		cout << " -- price("<< price <<")--" << endl;	
	}
	~Goods(){cout << "~~~Goods()" << endl;}
	double getPrice(){
		return price;	
	}
};

class Camera : public Goods{
	public:
		Camera(double price):Goods(price){cout << "---Camera--" << endl;}
		void take(const char* obj){
			cout << obj << " photo...." << endl;	
		}
		~Camera(){cout << "---~Camera--" << endl;}
};

class Mp3:public Goods{
	public:
		Mp3(double price):Goods(price){cout << "--Mp3---" << endl;}
		void play(const char* song){
			cout << song << " sing..." << endl;
		}
		~Mp3(){cout << "--~Mp3---" << endl;}
};

class Phone:public Goods{
	public:
		Phone(double price):Goods(price){cout << "--Phone--" << endl;}
		void dial(const char* no){
			cout << no << " tell..." << endl;	
		}
		~Phone(){cout << "~~Phone--" << endl;}
};

class ModernPhone : public Phone{
	string name;
	//組合
	Camera c;
	Mp3 m;
	Goods g;
	public:
	ModernPhone(const char* name,double price):\
		name(name),Phone(price-1),\
		//虛基類的成員由最底層繼承者初始化,Goods(price)
		m(price-3),c(price-5),g(price)
	{
		cout << name << "---ModernPhone----" << endl;	
	}
	void visitnet(const char* net){
		cout << "--visit-- " << net << endl;
	}
	~ModernPhone(){cout << "--~~~~ModernPhone----" << endl;}
	void take(const char* obj){
		c.take(obj);
	}
	void play(const char* song){
		m.play(song);
	}
	double getPrice(){
		return g.getPrice();	
	}
};

int main(){
	ModernPhone mp("apple",36.44);
	mp.dial("110");
	mp.play("sing sing sing a song");
	mp.visitnet("www.google.com");
	mp.take("Mizu");
	cout << "------------------------ " << endl;
	cout << mp.getPrice() << endl;
	return 0;
}





