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
		Person(string name,bool gender):\
			name(name),gender(gender){
				cout << " -- Person() --" << endl;
			}
		//虛函數，指針類型調用的是對象的類型，
		//而不是父類的指針類型,多態實現
		virtual void show()const;
		virtual ~Person(){}
};

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
	void show()const{
		cout << name << " ++++ hello !!!!" << endl;
	}
	~Teacher(){}
};

int main(){
	Person a("Mizu",true);
	Teacher b("Jun",false,"Unix");
	Person* p = NULL;
	Person* q = NULL;
	p = &a;
	q = &b;
	p->show();
	q->show();
	Person c = b;
	Person& d = b;
	c.show();
	d.show();
	b.show();

	/* 	
	 *  cout << dynamic_cast<Teacher*>(p) << endl;
	 * 	cout << dynamic_cast<Teacher*>(q) << endl;
	 * 	cout << dynamic_cast<Teacher*>(&c) << endl;
	 * 	cout << dynamic_cast<Teacher*>(&d) << endl;
	 */
	return 0;
}




