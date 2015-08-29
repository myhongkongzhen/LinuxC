/*
 * =====================================================================================
 *
 *       Filename:  overload.cpp
 *
 *    Description:  默認函數 
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 08时39分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//給形參指定默認值
//默認值在聲明中指定
//定義中不用再次指定默認值
void print(int a[],int n,char c = ' ', bool b = false);

//有默認值的形參只能靠右
void print(int a[],int n,char c , bool b ){
	if(b){
		cout << '[';
	}
	if(n > 0)cout << *a;
	for(int i = 1 ; i < n ; i++){
		cout << c << a[i] ;
	}
	if(b){
		cout << ']';
	}
	cout << endl;
}

int main(){
	int a[3] = {11,22,33};
	print(a,3);
	print(a,3,'^');
	print(a,3,',',true);
	print(a,3,'*',false);
	return 0;
}





