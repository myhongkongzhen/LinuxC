/*
 * =====================================================================================
 *
 *       Filename:  zy009.c
 *
 *    Description:  作用
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 13时02分19秒
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
#include <string.h>
#define swap(a,b){date* t = a ; a = b ; b = t ;}

typedef unsigned short int uint16;
typedef struct date{
	uint16 year;	
	uint16 month;	
	uint16 day;	
}date;

void input(date const* d){
	scanf("%d%d%d",&d->year,&d->month,&d->day);
}

void print(date const*const d){
	printf("%d-%d-%d ",d->year,d->month,d->day);
}

void foreach(void (*fun)(),date d[]){
	int i = 0 ; 
	for(; i < 3 ; i ++){
		fun(d+i);
	}
}

int roteByCondition(date* d1,date* d2,char* str){
	if (!strcmp(str,"year"))
		return (d1->year < d2->year);
	else if(!strcmp(str,"month"))
		return (d1->month > d2->month);
	else
		return (d1->day > d2->day);
}

void sortByCondition(date d[],char* str){
	int i = 0;
	int j ;
	for(; i < 3; i ++){
		for(j = i+1; j < 3; j ++){
			if(roteByCondition(&d[i],&d[j],str))		
				swap((d+i),(d+j));
		}
	}
}

int main(){
	date d[3];
	printf("please input three date (year-month-day):\n");
	foreach(input,d);
	foreach(print,d);
	sortByCondition(d,"year");
	foreach(print,d);
	/* 	int i = 0 ;
	 * 	for(; i < 3 ; i ++){
	 * 		input(&d[i]);
	 * 	}
	 * 	for(i = 0; i < 3; i ++){
	 * 		print(&d[i]);
	 * 	}
	 */
	printf("\n");
	return 0;
}

