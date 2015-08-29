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
	person a[3] = {};
	//3*24

	//b在任何系統，按照原樣寫入，不做轉換
	FILE* fo = fopen("person.dat","rb");
	if(fo == NULL){
		printf("open file error");
		return 1;
	}

	//fread/fwrite(內存地址，每個元素字節數，元素個數，文件)
	fread(a,sizeof(person),3,fo);
	//12+72
	int b[3]={};
	//84+2==86
	short s = 0;
	fread(&b,sizeof(int),3,fo);
	fread(&s,sizeof(short),1,fo);

	int i;
	for(i = 0 ; i < 3 ; i ++){
		printf("%s(%d) ",(a+i)->name,(a+i)->age);
	}
	printf("\n");

	for(i = 0 ; i < 3 ; i ++){
		printf("(%d) ",b[i]);
	}
	printf("\n");
	printf("%hd\n",s);

	fclose(fo);
	return 0;
}



