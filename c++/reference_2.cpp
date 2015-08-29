/*
 * =====================================================================================
 *
 *       Filename:  reference_2.cpp
 *
 *    Description:  引用
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 07时23分45秒
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

//不起任何作用
void swap_(int a,int b){
	int t = a; 
	a = b;
	b = t;
}

/* 函數名相同，參數類型不同：重載 */

//通過地址交換
void swap(int* a,int* b){
	int t = *a; 
	*a = *b;
	*b = t;
}

//通過引用交換本身
void swap(int& a,int& b){
	int t = a; 
	a = b;
	b = t;
}

/*
 * 建議使用引用作為形參，同時加上const禁止其值被修改
 * (1)如果不用引用，就意味著要複製一份數據
 * (2)如果使用引用，但未加const，就意味著，要改變變量的值
 */
void print(const int& n){
	cout << &n << '\t' << hex << showbase << n << endl;
	cout << noshowbase ;
}

struct Window{
	string text;
	int width;
	int height;
	int x,y;
};

void input(Window& w){
	cout << "please input window infos(text,height,width,x,y) : " << endl;
	cin >> w.text >> w.height >> w.width >> w.x >> w.y;
}

void input(Window* w){
	cout << "please input window infos(text,height,width,x,y) : " << endl;
	cin >> w->text >> w->height >> w->width >> w->x >> w->y;
}

void print(const Window& w){
	cout << "--------------" << w.text << "-------------" << endl;
	cout << "from (" << w.x << "," << w.y << ")" << endl;
	cout << "to   (" << (w.x+w.width) << "," << (w.y+w.height) << ")" << endl;
	cout << w.width << "*" << w.height << endl;
}

int main(){
	{
		int a = 4;
		int b = 5;
		cout << a << '-' << b << endl;
		swap_(a,b);
		cout << a << '-' << b << endl;
		swap(&a,&b);
		cout << a << '-' << b << endl;
		swap(a,b);
		cout << a << '-' << b << endl;
		cout << &a << '\t' << &b << endl;
		print(a);
		print(b);
		print(a+b);
	}

	Window w;
	input(w);
	print(w);

	return 0;
}





