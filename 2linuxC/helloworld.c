/*
 * =====================================================================================
 *
 *       Filename:  helloworld.c
 *
 *    Description:  外星人的 HelloWorld
 *
 *        Version:  1.0
 *        Created:  2014年11月05日 10时33分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void alien( char * p )
{
	while( putchar( * ( p += * ( p + 1 )  - * p) ) );
	//p = p + *(p+1) -*p
}

int main()
{
	return alien( "BETHO! Altec oh liryom(a loadjudas!) dowd." ), 0;
}


