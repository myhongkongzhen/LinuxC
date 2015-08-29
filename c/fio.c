/*
 * =====================================================================================
 *
 *       Filename:  fio.c
 *
 *    Description:  文件輸入輸出
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 18时02分53秒
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
	FILE* fi = fopen("fio.c","r");
	if(fi == NULL){
		printf("打開文件失敗!");
		return 1;
	}
	char str[3000];
	fscanf(fi,"%s",str);
	fscanf(fi,"%s",str);
	fclose(fi);
	printf("--%s\n",str);

	FILE* fo = fopen("out","w");
	if(fo == NULL){
		printf("打開文件失敗!");
		return 1;
	}
	fprintf(fo,"向文件寫數據\n");
	fprintf(fo,"%s",str);
	fclose(fo);
	return 0;
}



