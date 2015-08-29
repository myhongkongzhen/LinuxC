/*
 * =====================================================================================
 *
 *       Filename:  commain.cpp
 *
 *    Description:  控制台輸入操作主函數
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 14时01分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <fstream>
typedef int T;
#include "zy_list.h" 

int main(int argv,char argc[]){
	char c;
	List l;
	char file[200];
	int pos,data;
	do{
		cout << "請按照如下格式輸入命令：" << endl;
		cout << "q 退出程序 " << endl;
		cout << "c 清空鏈錶" << endl;
		cout << "e 位置 刪除數據" << endl;
		cout << "i 位置 數據 插入數據" << endl;
		cout << "s 文件名 保存到文件" << endl;
		cout << "l 文件名 文件中的數據追加到鏈錶末尾" << endl;
		cin >> c;
		switch(c){
			case 'c':
				cout << "~~~~~~~~~c 清空鏈錶" << endl;
				l.setEmpty();
				l.travel();
				break;
			case 'e':
				cout << "~~~~~~~~~~e 位置 刪除數據" << endl;
				cout << "輸入要刪除數據的位置: " ;
				cin >> pos;
				l.emas(pos).travel();
				break;
			case 'i':
				cout << "~~~~~~~~i 位置 數據 插入數據" << endl;
				cout << "輸入要插入數據的位置和數據: " ;
				cin >> pos >> data;
				l.insert(data,pos).travel();
				break;
				//case 'q':
			case 's':
				{
					cout << "~~~~~~~~~s 文件名 保存到文件" << endl;
					cout << "輸入要文件名: " ;
					cin >> file;

					ofstream fo(file,ios::binary|ios::out);
					if(!fo){
						cout << "文件:" << file << "打開失敗！" << endl;
						continue;
					}

					int size = l.size();
					for(int i = 0 ; i < size; i ++){
						fo << l.get(i) << endl;
					}

					fo.close();
					cout << "數據保存到文件" << file << "中" << endl;
				}
				break;
			case 'l':
				{
					cout << "~~~~~~~~~~~l 文件名 文件中的數據追加到鏈錶末尾" << endl;
					cout << "輸入要文件名: " ;
					cin >> file;

					ifstream fi(file,ios::binary|ios::in);
					if(!fi){
						cout << "文件:" << file << "打開失敗！" << endl;
						continue;
					}

					T data;
					while(fi >> data){
						l.insert(data,l.size());
					}

					fi.close();
					cout << "數據從文件" << file << "中追加到鏈錶中" << endl;
					l.travel();
				}
				break;
			default:
				cout << "~~~~default~~~~~"  << endl;
				break;
		}
	}while(c != 'q');
	return 0;
}

