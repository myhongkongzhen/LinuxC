/*
 * =====================================================================================
 *
 *       Filename:  2-04vector.cpp
 *
 *    Description:  vector個性
 *					數組可以換成vector來用，簡單的不用換
 *
 *        Version:  1.0
 *        Created:  2014年08月09日 21时26分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
using namespace std;

int main(){
	vector<double> vd;
	for(int i = 0 ; i < 9 ; i ++){
		vd.push_back(i+0.1);
		cout << &*vd.begin() << ':';
		cout << vd.size() << '-' << vd.capacity() << endl;
	}
	cout << "--------------------" << endl;
	vector<double> vv;
	vv.reserve(9);
	for(int i = 0 ; i < 9 ; i ++){
		vv.push_back(i+0.5);
		cout << vv.size() << '-' << vv.capacity() << endl;
	}
	vd[3] = 465.68;
	vd.at(5) = 44.56;
	//越界，不檢查，不拋出異常
	for(unsigned int i = 0 ; i <= vd.size() ; i ++){
		cout << vd[i] << ' ';
	}
	cout << endl;
	try{
		//越界，檢查，拋出異常
		for(unsigned int i = 0 ; i <= vd.size() ; i ++){
			cout << vd.at(i) << ' ';
		}
	}catch(exception& e){
		cout << "ERROR:" << e.what() << endl;
		cout << "ERROR_TYPE:" << typeid(e).name() << endl;
	}
	cout << endl;
	//二維數組
	int m = 3, n = 5;
	void print(const vector< vector<int> >& v);
	vector< vector<int> > vvi(m,vector<int>(n));
	print(vvi);
	cout << "======================" << endl;
	vvi.resize(m+3);
	vvi[1].assign(9,6);
	vvi[5].assign(4,8);
	print(vvi);
	return 0;
}

void print(const vector< vector<int> >& v){
	for(unsigned int i = 0 ; i < v.size(); i ++){
		for(unsigned int j = 0 ; j < v[i].size(); j ++){
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}

