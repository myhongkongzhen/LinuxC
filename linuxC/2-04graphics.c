/*
 * =====================================================================================
 *
 *       Filename:  2-04graphics.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 15时35分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void diamond(int r){
	int x,y;
	for(y = 0 ; y <= 2*r ; y++){
		for(x = 0 ; x <= 2*r; x++){
			if(y == x+r || y == x-r || \
					y == -x+r || y == -x+3*r){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

