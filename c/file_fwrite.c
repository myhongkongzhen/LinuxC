/*
 * =====================================================================================
 *
 *       Filename:  file_bk.c
 *
 *    Description:  片段讀取
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 07时10分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct person{
	char name[20];//20
	int age;//4
}person;

int main(){
	person a[3] = {{"jun",20},{"mizu",23},{"tani",21}};
	//3*24

	//b在任何系統，按照原樣寫入，不做轉換
	FILE* fo = fopen("person.dat","wb");
	if(fo == NULL){
		printf("open file error");
		return 1;
	}

	//fread/fwrite(內存地址，每個元素字節數，元素個數，文件)
	fwrite(a,sizeof(person),3,fo);
	//12+72
	int b[3]={1,2,4};
	//84+2==86
	short s = 1244;
	fwrite(&b,sizeof(int),3,fo);
	fwrite(&s,sizeof(short),1,fo);

	fclose(fo);
	return 0;
}



