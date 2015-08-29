/*
 * =====================================================================================
 *
 *       Filename:  9-05getip.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 14时42分27秒
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
#include <netdb.h>

int main(){

	struct hostent *ent;
	ent = gethostbyname("www.sina.com");
	printf("%s\n",ent->h_aliases[0]);
	printf("%hhu.%hhu.%hhu.%hhu\n",ent->h_addr_list[0][0],
			ent->h_addr_list[0][1],ent->h_addr_list[0][2],
			ent->h_addr_list[0][3]);
	return 0;
}

