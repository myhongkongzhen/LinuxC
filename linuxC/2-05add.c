/*
 * =====================================================================================
 *
 *       Filename:  2-05add.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 18时15分27秒
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

int add(it ipt){
	printf("%d=%d\n",ipt.a,ipt.b);
	return ipt.a + ipt.b;
}

