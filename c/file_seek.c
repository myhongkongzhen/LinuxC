/*
 * =====================================================================================
 *
 *       Filename:  file_seek.c
 *
 *    Description:  文件定位讀寫
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 06时48分48秒
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

int main(){
	FILE* fp = fopen("out","r+");
	if(fp == NULL){
		printf("open file error");
		return 1;
	}

	char c10,c20;
	//文件頭開始定位
	fseek(fp,9,SEEK_SET);
	c10 = getc(fp);
	//當前位置開始定位
	fseek(fp,9,SEEK_CUR);
	c20 = getc(fp);

	fseek(fp,-11,SEEK_CUR);
	putc(c20,fp);
	//文件尾開始定位，文件尾包含換行符
	fseek(fp,-8,SEEK_END);
	putc(c10,fp);

	fseek(fp,0,SEEK_SET);
	char c;
	while((c = fgetc(fp)) != EOF){
		putchar(c);
	}

	fclose(fp);
	return 0;
}



