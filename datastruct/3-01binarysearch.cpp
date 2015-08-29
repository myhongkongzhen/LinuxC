/*
 * =====================================================================================
 *
 *       Filename:  3-01binarysearch.cpp
 *
 *    Description:  二分法查找
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 11时20分25秒
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
	string name;
	int age;
	string addr;
	public:
	Person(const char* name,int age,const char* addr):\
		name(name),age(age),addr(addr){}
	friend bool operator < (const Person& a,const Person& b){
		return a.name < b.name;		
	}
	friend bool operator == (const Person& a,const Person& b){
		return a.name == b.name;
	}
	friend ostream& operator << (ostream& o, const Person& a){
		o << a.name << '=' << a.age << '=' << a.addr;	
		return o;
	}
};

//遞歸實現二分法查找
/* Person* binarysearch(Person* p,int n,const string& name){
 * 	if(n <= 0){
 * 		return NULL;	
 * 	}	
 * 	int mid = n/2;
 * 	Person t(name.c_str(),0,"");
 * 	if(p[mid] == t){
 * 		return p + mid;
 * 	}
 * 	if(t < p[mid]){
 * 		return binarysearch(p,mid,name);
 * 	}else {
 * 		return binarysearch((p + mid + 1),(n - mid - 1),name);
 * 	}
 * }
 */

//通過記錄首尾位置實現二分法查找
Person* binarysearch(Person* p,int n,const string& name){
	Person t(name.c_str(),0,"");
	//--首------尾
	int b = 0 ,e = n-1;
	while(b <= e){
		int mid = (b+e)/2;
		if(p[mid] == t){
			return p+mid;
		}
		if(t < p[mid]){
			e = mid - 1;
		}else{
			b = mid + 1;
		}
	}
	return NULL;
}

int main(){
	Person p[4] = {Person("Tani",23,"Japan"),
		Person("Jun",25,"Japan"),
		Person("Mizu",24,"Japan"),
		Person("Aran",26,"Japan"),
	};

	for(int i = 0 ; i < 4; i ++){
		for(int j = i + 1 ; j < 4; j ++){
			if(p[j]<p[i]){
				swap(p[j],p[i]);
			}
		}
	}
	for(int i = 0 ; i < 4; i ++){
		cout << p[i] << endl;
	}

	cout << "please name : " ;
	string name;
	cin >> name;
	Person* fp =  binarysearch(p,4,name);
	if(fp){
		cout << *fp << endl;
	}else{
		cout << "No Match!" << endl;
	}

	return 0;
}

