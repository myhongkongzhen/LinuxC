/*
 * =====================================================================================
 *
 *       Filename:  manipulator.cpp
 *
 *    Description:  格式操作符重載
 *
 *        Version:  1.0
 *        Created:  2014年08月02日 19时57分03秒
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

//無慘的，可以看做是對象，也可以是函數
class __HEXUB{
	friend ostream& operator <<(ostream& o, const __HEXUB& h){
		o << hex << uppercase << showbase;
		return o;
	}
};

const __HEXUB hexub = __HEXUB();

//無慘的，可以看做是對象，也可以是函數
ostream& showdecpos(ostream& o){
	o << dec << showpos;
	return o;
}

class wf{
	unsigned int w;
	char fill;
	public:
	wf(unsigned int w,char fill = ' ') :w(w),fill(fill){};	
	friend ostream& operator <<(ostream& o,const wf& f){
		o.width(f.w);
		o.fill(f.fill);
		return o;
	}
};

int main(){
	cout << hexub << 123 << endl;
	//-----可以看做是匿名對象
	cout << wf(10,'*') << "good" << endl;
	cout << wf(8) << "good" << endl;
	cout << wf(12,'#') << "good" << endl;
	cout << showdecpos << 123 << endl;
	return 0;
}

