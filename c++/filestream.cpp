/*
 * =====================================================================================
 *
 *       Filename:  filestream.cpp
 *
 *    Description:  文件操作
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 21时29分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>//文件頭文件
#include <string>
using namespace std;

int main(){
	ofstream fout ("democopy");
	if(!fout){
		cout << "open file error" << endl;
		return 1;
	}
	string path = "demo.cpp";
	ifstream fin(path.c_str());
	//fin.open(path.c_str());
	if(!fin){
		cout << "open file error" << endl;	
		return 1;
	}

	char ch;
	//每個字符都讀入
	//	fin.get();
	//跳過空白字符
	//fin >> ch
	
	//while(fin >> ch){
	//while((ch = fin.get()) != EOF){ // ×
	while(fin.get(ch)){// √
		cout << ch;
		fout << ch;
	}

	//及時關閉文件
	fout.close();
	fin.close();
	return 0;
}

