/*
 * =====================================================================================
 *
 *       Filename:  inheriance.cpp
 *
 *    Description:  繼承
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 09时19分33秒
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

class Person{
	protected:
		string name;
	private:
		bool gender;
	public:
		Person(string name,bool gender):name(name),gender(gender){
			cout << " -- Person() --" << endl;
		}
		void eat(const char* food);
		void sleep();
		void show()const;
		/* 		string& getName()const{
		 * 			return name;
		 * 		}
		 */
		string nameInfo()const{
			return name;
		}
		void setName(const char* name){
			this->name = name;
		}
};

void Person::eat(const char* food){
	cout << name << " eat " << food << endl;
}
void Person::sleep(){}
void Person::show()const{
	cout << name << (gender?" == Girl":" == Boy") << " showing!!!!" << endl;
}

class Teacher : public Person{
	string course;
	public:
	Teacher(const char* name,bool gender,const char* course)\
		:Person(name,gender),course(course){
			cout << "Teacher()" << endl;
		}
	void teach(const char* clazz)
	{
		cout << name << " == " << clazz << " teach " << course << endl;	
		//		cout << getName()<< " == " << clazz << " teach " << course << endl;	
	}
	//會隱藏父類同名函數，即使子類中參數表不同，也會隱藏父類
	//同名函數
	void show(const char* s){
		cout << name << " ++++ hello !!!!" << s << endl;
	}
};

int main(){
	Person a("Mizu",true);
	Person b("Jun",false);
	cout << "---------------" << endl;
	Teacher c("Aran",true,"uta");
	cout << "---------------" << endl;
	Person d("Tani",false);
	a.eat("巧克力");
	b.eat("梨");
	c.eat("蘋果");
	d.eat("バナナ");
	c.teach("class-78");
	a.show();
	b.show();
	cout << "---------------" << endl;
	c.show(" -- show(teacher)--");
	//c.show();//不會尋找父類同名函數
	c.setName("AranKei");
	c.show(" -- show(teacher)--");
	cout << "---------------" << endl;
	d.show();
	cout << a.nameInfo() << endl;
	cout << b.nameInfo() << endl;
	/* 	cout << c.name << endl;
	 * 	cout << d.name << endl;
	 */
	return 0;
}




