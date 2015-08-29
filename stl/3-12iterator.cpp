/*
 * =====================================================================================
 *
 *       Filename:  3-12iterator.cpp
 *
 *    Description:  特殊迭代器
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 04时38分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#include "3-print.h"

int main(){
	//輸入迭代器
	istream_iterator<int> in(cin);
	istream_iterator<int> end;
	vector<int> vi;
	copy(in,end,back_inserter(vi));
	cout << endl << "--------------------" << endl;
	print(vi.begin(),vi.end());
	cout << endl << "--------------------" << endl;
	ostream_iterator<int> o(cout,"|");
	copy(vi.begin(),vi.end(),o);
	cout << endl;
	ofstream fo("file.txt");
	ostream_iterator<int> oi(fo," ");
	copy(vi.begin(),vi.end(),oi);
	fo << endl;
	ifstream fi("file.txt");
	istream_iterator<int> fii(fi);
	vector<int> vii;
	copy(fii,end,back_inserter(vii));
	cout << endl << "--------------------" << endl;
	print(vii.begin(),vii.end(),',');

	return 0;
}

