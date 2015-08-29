/*
 * =====================================================================================
 *
 *       Filename:  fileCopy.cpp
 *
 *    Description:  文件加密複製 
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 07时52分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
using namespace std;

void encode(char* buf,int bytes){
	for(int i = 0 ;  i < bytes ;  i ++){
		++*buf++;
	}
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	if(argc != 3){
		cout << "please input source file and desc file" << endl;
		return 1;
	}

	/*
	 * ios::binary
	 * ios::in
	 * ios::out
	 * ios::app(append)
	 */	
	ifstream fi(argv[1],ios::binary|ios::in);
	if(!fi){
		cout << "open file error!" << endl;
		return 1;
	}
	ofstream fo(argv[2],ios::binary|ios::out);
	if(!fo){
		cout << "open file error!" << endl;
		return 1;
	}

	char buf[300];
	while(fi){
		//需要char*的內存地址影射，需要轉換
		fi.read(/*(char *)*/buf,sizeof(buf));	
		encode(buf,fi.gcount());
		//寫入讀取的字節數
		fo.write(buf,fi.gcount());//不要用sizeof(buf)
		//標準轉換用這個，但是建議這裡直接強制類型轉換
		//fo.write(reinterpret_cast<char*>(buf),fi.gcount());//不要用sizeof(buf)
		cout.write(buf,fi.gcount());
	}

	//close可以不寫，析構函數會自動調用關閉，但最好寫上
	fo.close();
	fi.close();

	return 0;
}				/* ----------  end of function main  ---------- */

