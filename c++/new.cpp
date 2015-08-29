/*
 * =====================================================================================
 *
 *       Filename:  new.cpp
 *
 *    Description:  new和delete重載
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 08时11分04秒
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

char mem[100000];
int pos = 0;

class A{
	public:
		A(){
			cout << "-A()-" << endl;
		}
		~A(){
			cout << "-~A()-" << endl;
		}
		//static寫不寫都是靜態成員函數
		static void* operator new(size_t bytes){
			cout << "new A --" << bytes << endl;
			int alloc = pos;
			pos += bytes;
			return mem+alloc;
		}
		//static寫不寫都是靜態成員函數
		static void operator delete(void* p){
			cout << "delete A" << endl;
		}
		static void* operator new[](size_t bytes){
			cout << "new[] A --" << bytes << endl;
			int alloc = pos;
			pos += bytes;
			return mem+alloc;
		}
		static void operator delete[](void* p){
			cout << "delete[] A" << endl;
		}
};

void* operator new(size_t bytes){
	cout << "new " << bytes << endl;
	return mem;
}
void operator delete(void* p){
	cout << "delete" << endl;
}

int main(){
	/* 
	 * 1分配空間，2執行構造函數
	 */
	A* x = new A;
	/*
	 * 1執行析構函數，2釋放空間
	 */
	delete x;
	x = new A[3];
	delete[] x;
	int* p = new int;
	delete p;
	return 0;
}





