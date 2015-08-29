/*
 * =====================================================================================
 *
 *       Filename:  temp_object.cpp
 *
 *    Description:  匿名對象，臨時對象
 *
 *        Version:  1.0
 *        Created:  2014年07月30日 17时46分58秒
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

class Teacher{
	string name;
	string course;
	public:
	Teacher(const char* name,const char* course)\
		:name(name),course(course){
			cout << name << " teach " << course << endl;	
		}
	Teacher(const Teacher& tea)\
		:name(tea.name),course(tea.course){
			cout << name << " teach(copy) " << course << endl;	
		}

	~Teacher(){
		cout << name << " no teach!!" << endl;	
	}
};

int main(){
	//自動釋放，自動調用析構函數
	Teacher t1("czq","c++");
	Teacher t2 = t1;;
	//臨時變量初始化對象，編譯器優化
	//匿名變量
	cout << "-------------------" << endl;
	//編譯器優化，直接用匿名變量的參數，初始化創建變量
	Teacher t3 = Teacher("yq","unix");
	cout << "-------------------" << endl;
	cout << "===================" << endl;
	//這裡編譯器不做優化，所以匿名變量創建，賦值，銷毀
	t2 = Teacher("xww","oracle");
	cout << "===================" << endl;
	return 0;
}





