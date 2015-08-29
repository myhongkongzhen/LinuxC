/*
 * =====================================================================================
 *
 *       Filename:  fun_pointer.c
 *
 *    Description:  指向函數的指針
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 08时13分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int* f(char);//f是一個函數，形參是char，返回值是int*
	int(*p)(char);//p是一個指針，指向一個形參char，返回類型int的函數
	int(*q)();//q是一個指針，指向一個形參任意，返回類型int的函數
	//函數名本身就是函數的地址，&取地址符號，可有可無
	printf("main = %p \n",main);
	printf("&main = %p \n",&main);
	//	p = &main;//錯誤
	q = &main;
	//	printf("&main = %p \n",*q);
	if(argc>0){
		(*q)(argc-1,argv);//更傾向於這種方式
		q(argc-1,argv);//一樣可以調用函數指針
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


