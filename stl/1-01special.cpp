/*
 * =====================================================================================
 *
 *       Filename:  1-01special.cpp
 *
 *    Description:  模板特化
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 18时45分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <typeinfo>
using namespace std;

template <int n>
class Fact{
	public:
		enum {val = Fact<n-1>::val * n};
};
template <>
class Fact<0>{
	public:
		enum {val = 1};
};

template < typename T >
class Type{
	public:
		static string name(){
			return typeid(T).name();	
		}
};
template <>
class Type<char>{
	public:
		static string name(){
			return "char";
		}
};
template <>
class Type<double>{
	public:
		static const char* const name;
};

const char* const Type<double>::name = "double";

template < typename T >
class Type<T*>{
	public:
		static string name(){
			return Type<T>::name()+" pointer";
		}
};

int main(){
	cout << Fact<5>::val << endl;
	cout << Type<double>::name << endl;
	cout << Type<char>::name() << endl;
	cout << Type<int*>::name() << endl;
	cout << Type<char*>::name() << endl;
	return 0;
}

