/*
 * =====================================================================================
 *
 *       Filename:  1-04class.cpp
 *
 *    Description:  類模板
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 00时44分16秒
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

template < typename To,typename From >
To convertto(From v){
	return To(v);
}
template < typename To >
To convertto(const char* str){
	return To(atof(str));
}

template < typename T, typename U >
struct Pair{
	T first;
	U second;
	Pair():first(),second(){}
	Pair(const T& f,const U& s):first(f),second(s){}
	template < typename X,typename Y >
		Pair& operator =(const Pair<X,Y>& p){
			first = convertto<T>(p.first);
			second = convertto<U>(p.second);
			return *this;
		}
};

template < typename T,typename U >
ostream& operator << (ostream& o,const Pair<T,U>& p){
	return o << p.first << '~' << p.second;
}

template < typename T,typename U >
Pair<T,U> mp(T t,U u){
	return Pair<T,U>(t,u);
}	

int main(){
	cout << Pair<const char*,int>("mizu",23) << endl;	
	cout << Pair<string,int>("tani",20) << endl;	
	cout << Pair<int,double>(20,45.52) << endl;	
	cout << Pair<int,const char*>(26,"aran") << endl;	
	cout << mp(24,"jun") << endl;
	Pair<int,double> p(12,34.56);
	cout << p << endl;
	Pair<const char*,const char*> q("8.8","2.41");
	p = q;
	cout << "~~~~~~~~~~~~~~~~~~~" << endl;
	cout << p << endl;
	return 0;
}

