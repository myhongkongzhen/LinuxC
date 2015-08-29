/*
 * =====================================================================================
 *
 *       Filename:  3-02getenv.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 23时58分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(){
	char* val = getenv("HOME");
	printf("%s\n",val);
	return 0;
}

