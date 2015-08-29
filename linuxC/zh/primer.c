/*
 * =====================================================================================
 *
 *       Filename:  isPrimer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 19时45分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int isPrimer(int a){
	int i;
	for(i = 2 ; i < a; i ++){
		if(a%i == 0){
			return 0;
		}
	}
	return 1;
}

