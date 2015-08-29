/*
 * =====================================================================================
 *
 *       Filename:  file.c
 *
 *    Description:  文件輸入輸出
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 17时23分06秒
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
	char str[200];
	//stdout,stdin,stderr標準輸入輸出
	fprintf(stdout,"please input name:");
	//sleep(5);
	fscanf(stdin,"%s",str);
	fprintf(stdout,"%s Hello!\n",str);
	return 0;
}



