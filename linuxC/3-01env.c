/*
 * =====================================================================================
 *
 *       Filename:  3-01env.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 23时33分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <unistd.h>

extern char** environ;

//int main(int args,char* argv[],char* arge[]){
int main(int args,char** argv,char** arge){
	while(*arge){
		printf("%s\n",*arge++);
	}
	printf("========================\n");
	while(*environ){
		printf("%s\n",*environ++);
	}
	return 0;
}

