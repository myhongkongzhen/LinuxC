/*
 * =====================================================================================
 *
 *       Filename:  2-02container.cpp
 *
 *    Description:  標準容器
 *
 *        Version:  1.0
 *        Created:  2014年08月08日 23时45分22秒
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
#include <vector>
#include <algorithm>
#include "print.h"

int main(){
	int a[5] = {22,11,55,33,44};
	//vector<int>和模板組合才是一個真正的類型名 
	//------------區間構造函數
	vector<int> vi(a,a+5);
	cout << vi.size() << endl;
	//容器里的數據排序，a數組沒有變化
	sort(vi.begin(),vi.end());
	//是vector<int>類型中的內部類iterator迭代器
	vector<int>::iterator it = vi.begin();
	while(it != vi.end()){
		cout << *it++ << ' ';
	}
	cout << endl;
	cout << "---------------------" << endl;
	print(vi.begin(),vi.end());
	print(a,a+5);
	//倒序輸出,反向迭代器
	print(vi.rbegin(),vi.rend());
	vi.insert(++++vi.begin(),66);
	print(vi.begin(),vi.end());
	vi.insert(vi.begin(),88);
	vi.insert(vi.end(),77);
	print(vi.begin(),vi.end());
	cout << vi.size() << '-' << vi.max_size() << endl;
	vi.erase(------vi.end());
	print(vi.begin(),vi.end());
	vi.erase(++++vi.begin(),--vi.end());
	print(vi.begin(),vi.end());

	vector<int> v2(a,a+5);
	print(v2.begin(),v2.end());
	cout << "=====old=============" << endl;
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	cout << "------new--------" << endl;
	vi.swap(v2);
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	swap(vi,v2);
	cout << "------new 2--------" << endl;
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	vector<int> tmp = vi;
	vi = v2;
	v2 = tmp;
	cout << "------new 3-------" << endl;
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	vi.clear();
	cout << vi.size() << endl;
	print(vi.begin(),vi.end());
	cout << "----------------" << endl;

	//	cout << vi.capacity() << endl;
	return 0;
}

