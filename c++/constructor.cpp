/*
 * =====================================================================================
 *
 *       Filename:  constructor.cpp
 *
 *    Description:  構造器
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 09时39分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

class Person{
	string name;
	bool gender;
	int age;

	Person* lover;

	public:
	Person(const char* n="no name",bool g = true);
	void growup(int year);
	void show();
	void marry(Person& lover);

};

void Person::marry(Person& other){
	//雙向關係，兩人結婚
	this->lover = &other;
	other.lover = this;
}

//Person::Person(const char* n,bool g){
//Person::Person(const char* name,bool gender)
//初始化成員變量列表,格式為 :成員變量(初始值),....
//初始化列表在定義里，不在聲明里
Person::Person(const char* name,bool gender) \
		:name(name),gender(gender)
{
	//	cout << "two params constructor" << endl;
	//表示整個對象的用*this，單單this只是個指針

	//有了初始化列表，這裡就可以不用寫了

	/* 	//	(*this).name = name;
	 * 	this->name = name;
	 * 	this->gender = gender;
	 */
	(*this).age = 0;
	this->lover = NULL;
}

void Person::growup(int year){
	if( year < 0){
		year = -year;
	}
	age += year;
}

void Person::show(){
	cout << name << " [age : " << age << "] " << (gender?"MALE":"FEMALE") << " show yourself" << endl;
	if(lover != NULL){
		cout << name << " and " << lover->name << " married" << endl;
	}else{
		cout << "~~~~~~~~single~~~~~~~" << endl;
	}
}

int main(){
	Person a("Tani",false);
	Person b("Jun",true);
	//調用成員函數的時候，會把對象的地址作為參數傳遞過去
	a.growup(18);//growup(&a,18);
	b.growup(-23);//growup(&b,-23);

	a.marry(b);

	a.show();
	b.show();

	Person c("Aran");
	c.growup(26);
	c.show();

	Person d;
	d.growup(22);
	d.show();

	/* 
	 *  其實是一個函數聲明
	 *  函數名為e，形參空，返回類型為Person
	 */
	Person e();
	/*
	 * 	所以這裡不能通過編譯
	 * 	e.growup(22);
	 */
	e().show();

	d.marry(c);
	d.show();
	c.show();

	return 0;
}

Person e(){
	string name;
	bool gender;
	cout << "please input name and gender" << endl;
	cin >> name >> gender;

	Person input(name.c_str(),gender);
	input.growup(28);
	return input;

}




