/*
 * =====================================================================================
 *
 *       Filename:  3-02bubble.cpp
 *
 *    Description:  冒泡排序
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 13时17分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

template < typename T >
void sort(T a[],int n){
	bool changed = true;
	do{
		changed = false;
		for(int i = 1 ; i < n ; i ++){
			if(a[i] < a[i-1]){
				swap(a[i-1],a[i]);
				changed = true;
			}
		}
		--n;
	}while(changed);
}

template < >
void sort(const char* a[],int n){
	bool changed = true;
	do{
		changed = false;
		for(int i = 1 ; i < n ; i ++){
			if(strcmp(a[i] , a[i-1]) < 0){
				swap(a[i-1],a[i]);
				changed = true;
			}
		}
		--n;
	}while(changed);
}

//template < class T >
template < typename T ,int N>
void print(T(&a)[N]){
	int n = sizeof(a)/sizeof(a[0]);
	for(int i = 0 ; i < n ; i ++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

template <typename T>
void print(T data){
	cout << data ;
}

struct Date{
	int year;
	int month;
	int day;
	bool operator < (const Date& d){
		if(this->year < d.year){
			return true;
		}
		if(d.year < this->year){
			return false;
		}
		if(this->month < d.month){
			return true;
		}
		if(d.month < this->month){
			return false;
		}
		if(this->day < d.day){
			return true;
		}
		if(d.day < this->day){
			return false;
		}
		return true;
	}
};

ostream& operator << (ostream& o,const Date& d){
	return o << d.year << '-' << d.month << '-' << d.day;;
}

int main(){
	double m = 34.44;
	print(m);
	cout << endl;
	int a[] = {1,4,2,7,8};
	sort(a,5);
	print(a);
	char b[] = {'b','e','a','d','f'};
	sort(b,5);
	print(b);
	Date d[3]={{2006,12,5},{2006,5,8},{2010,5,7}};
	sort(d,3);
	print(d);
	const char* s[3] = {"mizu","tani","jun"};
	sort(s,3);
	print(s);
	return 0;
}

