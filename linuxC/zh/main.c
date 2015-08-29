/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 19时49分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(){
	int a = inputInt();
	int r = isPrimer(a);
	printf("%d%s\n",a,(r?" is primer!":" is not primer!"));
	return 0;
}

