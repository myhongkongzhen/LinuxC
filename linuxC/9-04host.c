/*
 * =====================================================================================
 *
 *       Filename:  9-04host.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 14时30分52秒
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
	/* open host config */
	sethostent(1);

	while(1){
		ent = gethostent();
		if(ent == 0){
			break;
		}
		printf("name:%s IP name:%hhu.%hhu.%hhu.%hhu alarm:%s\n",
				ent->h_name,ent->h_addr[0],
				ent->h_addr[1],ent->h_addr[2],
				ent->h_addr[3],ent->h_aliases[0]);
	}

	endhostent();
	return 0;
}

