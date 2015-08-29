/*
 * =====================================================================================
 *
 *       Filename:  fileCopy.cpp
 *
 *    Description:  文件加密複製 ,定位讀寫
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

void decode(char* buf,int bytes){
	for(int i = 0 ;  i < bytes ;  i ++){
		--*buf++;
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
	if(argc != 3 || 
			strcmp(argv[1],"-e")&&strcmp(argv[1],"-d")){
		cout << "please input source file and -e|-d" << endl;
		return 1;
	}

	/*
	 * in.seekg()(seekget)
	 * out.seekp()(seekput)
	 * in.tellg()當前位置
	 * out.tellp()
	 * ios::beg
	 * ios::end
	 * ios::cur
	 */	
	fstream fio(argv[2],ios::binary|ios::in|ios::out);
	if(!fio){
		cout << "open file error!" << endl;
		return 1;
	}

	bool buf[300];
	//函數指針來實現循環內部的重複判斷
	void(*p)(char*,int) = ((argv[1][1] == 'e')?encode:decode);
	int pos1 = 0 ;
	int pos2 = 0;
	int bytes ;
	bool ok = true;
	while(ok){
		//到這個地方讀文件內容
		fio.seekg(pos1); //fio.seekg(pos1,ios::beg);
		fio.read((char*)buf,sizeof(buf));	
		//文件出現錯誤狀態
		if(!fio){
			//錯誤狀態繼續工作，要clear一下
			fio.clear();
			ok = false;
		}
		//讀取后的文件新位置
		pos2 = fio.tellg();
		bytes = fio.gcount();
		p((char*)buf,bytes);
		//cout.write((char*)buf,bytes);
		fio.seekp(pos1);//fio.seekp(-bytes,ios::cur);
		fio.write((char*)buf,bytes);//不要用sizeof(buf)	
		//下次讀文件從剛剛的位置讀取
		pos1 = pos2;
	}

	//close可以不寫，析構函數會自動調用關閉，但最好寫上
	fio.close();

	return 0;
}				/* ----------  end of function main  ---------- */

