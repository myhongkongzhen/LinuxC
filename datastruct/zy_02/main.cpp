/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  二叉查找樹主函數
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 15时22分11秒
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

typedef int T;
#include "bstree.h"

int main(){
	bstree bt;
	bt.insert(3).insert(34).insert(4);
	bt.insert(9);
	bt.printtree();
	cout <<	bt.size() << endl;
	bt.clear();
	cout <<	bt.size() << endl;
	bt.insert(213).insert(34).insert(4);
	bt.insert(13).insert(434).insert(84);
	bt.insert(39).insert(33).insert(112);
	bt.insert(68).insert(89).insert(93);//.travel();
	bt.insert(222).insert(877).insert(446);
	bt.printtree();
	cout << bt.remove(34) << endl;
	bt.travel();
	bt.remove(39);
	bt.travel();
	bt.edit(213,666);
	bt.travel();
	bt.edit(4,866).travel();
	cout << "-----------------------------" << endl;
	cout << bt.height() << endl;
	bt.printtree();
	cout << "-----------------------------" << endl;
	return 0;
}

