/*
 * =====================================================================================
 *
 *       Filename:  pointer_struct.c
 *
 *    Description:  結構指針
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 11时05分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
typedef unsigned short int uint16;
typedef struct date{
	uint16 year;
	uint16 month;
	uint16 day;
}date;

void print(const date * d){
	//	printf("%d-%d-%d ",(*d).year,(*d).month,(*d).day);
	printf("%d-%d-%d|",d->year,d->month,d->day);
}

int main(){
	date a[3]={{2008,8,8},{2014,3,28},{2014,7,24}};
	int i ;
	for(i = 0 ;  i< 3 ; i ++){
		print(&a[i]);	
	}
	printf("\n");
	return 0;
}



