/*
 * =====================================================================================
 *
 *       Filename:  2-04iotool.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 15时35分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int input(const char* info){
	int r;
	printf("%s:",info);
	scanf("%d",&r);
	return r;
}

