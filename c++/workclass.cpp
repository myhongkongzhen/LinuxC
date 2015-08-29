/*
 * =====================================================================================
 *
 *       Filename:  workclass.cpp
 *
 *    Description:  課堂作業
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 12时49分40秒
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

class USB{
	public:	
		USB(){}
		virtual void plugin(){
			cout << "~~~~~USBplugin~~~~" << endl;
		}
		virtual void work(){
			cout << "~~~~USBwork~~~" << endl;	
		}
		virtual void stop(){
			cout << "~~~~USBstop~~~~" << endl;	
		}
		virtual ~USB(){}
};
class USBDisk:public USB{
	public:
		USBDisk(){}
		void plugin(){cout << "--USBDisk(plugin)" << endl;}
		void work(){cout << "--USBDisk(work)" << endl;}
		void stop(){cout << "--USBDisk(stop)" << endl;}
		~USBDisk(){}
};
class USBFan:public USB{
	public:
		USBFan(){}
		void plugin(){cout << "--USBFan(plugin)" << endl;}
		void work(){cout << "--USBFan(work)" << endl;}
		void stop(){cout << "--USBFan(stop)" << endl;}
		~USBFan(){}
};
class Computer{
	public:
		Computer(){}
		void use(USB* u){
			u->plugin();
			u->work();
			u->stop();
		}
		~Computer(){}
}; 
class USBCamera:public USB{
	public:
		USBCamera(){}
		void plugin(){cout << "--USBCamera(plugin)" << endl;}
		void work(){cout << "--USBCamera(work)" << endl;}
		void stop(){cout << "--USBCamera(stop)" << endl;}
		~USBCamera(){}
};

int main(){
	//使用指針和引用來訪問虛函數，實現多態機制
	USB* ud = new USBDisk;
	USB* uf = new USBFan;
	USB* uc = new USBCamera;
	Computer c ;
	c.use(ud);
	c.use(uf);
	c.use(uc);
	return 0;
}




