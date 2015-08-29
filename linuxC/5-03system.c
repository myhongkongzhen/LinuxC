/*
 * =====================================================================================
 *
 *       Filename:  5-03system.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 17时29分47秒
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
#include <unistd.h>

int main(){
	printf("%d\n",getpid());
	sleep(3);
	return 44;
}

