/*
 * =====================================================================================
 *
 *       Filename:  file_position.c
 *
 *    Description:  文件定位讀寫
 *
 *        Version:  1.0
 *        Created:  2014年07月26日 21时27分20秒
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
	FILE* fi = fopen("out","r+");	
	if(fi == NULL){
		printf("open file error");
		return 1;
	}

	//文件讀寫共用一個坐標值
	char c;
	while((c = fgetc(fi)) != EOF){
		fputc(c,fi);	
	}
	fclose(fi);
	return 0;
}


