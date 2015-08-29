/*
 * =====================================================================================
 *
 *       Filename:  2-05input.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 18时12分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "2-05input.h"

it input(const char* s){
	it ipt ;
	printf("%s:",s);
	char c;
	scanf("%d%c%d",&ipt.a,&c,&ipt.b);
	printf("%d=%d\n",ipt.a,ipt.b);
	return ipt;
}

