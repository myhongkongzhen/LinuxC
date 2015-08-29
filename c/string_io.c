/*
 * =====================================================================================
 *
 *       Filename:  string_io.c
 *
 *    Description:  字符串輸入輸出到字符數組
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 12时45分46秒
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

//sscanf,sprintf
int main(){
	char buf[100];
	printf("---helle,i'm %s\n","zzw");
	sprintf(buf,"helle,i'm %s","zzw");
	puts(buf);
	int d = 0;
	char s[20] ;
	const char* str="30 lll";
	//scanf("%d%s",&d,s);
	sscanf(str,"%d%s",&d,s);
	printf("%d---%s\n",d,s);
	return 0;
}


