/*
 * =====================================================================================
 *
 *       Filename:  filecopy.c
 *
 *    Description:  文本文件拷貝功能
 *
 *        Version:  1.0
 *        Created:  2014年07月26日 20时59分56秒
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

int main(int argv,char* argc[]){
	if(argv != 3){
		printf("please input param");
		return 1;
	}

	FILE* fi = fopen(argc[1],"r");
	if(fi == NULL){
		printf("open file error");
		return 1;
	}

	FILE* fo = fopen(argc[2],"w");
	if(fo == NULL){
		printf("open file error");
		return 1;
	}

	char c;
	while((c = fgetc(fi)) != EOF){
		putchar(c);
		fputc(c,fo);
	}

	fclose(fo);
	fclose(fi);
	return 0;
}



