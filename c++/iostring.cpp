/*
 * =====================================================================================
 *
 *       Filename:  iostring.cpp
 *
 *    Description:  字符串io
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 21时07分40秒
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
#include <sstream> //字符串流
using namespace std;

class Point{
	int x;
	int y;
	public:
	Point(int x,int y):x(x),y(y){}
	friend ostream& operator << (ostream& o,const Point& p){
		return ( o << '(' << p.x << ',' << p.y << ')' );	
	}
};

int main(){
	string s = "1234 54.45 j hello";
	istringstream is(s);
	int a ;
	double b;
	char c;
	string str;
	is >> a >> b >> c >> str ;

	cout << a <<'-' << b << '-' << c << '-' << str << endl;
	cout << "__________________________" << endl;
	ostringstream os;
	Point p(3,5);
	os << a <<'-' << b << '-' << c << '-' << str << '=' << p<< endl;
	cout << os.str()<< endl;
	cout << os.str()[11] << endl;


	return 0;
}

