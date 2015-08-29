/*
 * =====================================================================================
 *
 *       Filename:  7-05sigaction.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 01时35分22秒
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
#include <unistd.h>
#include <signal.h>

int main(){

	union sigval val;
	val.sigval_int = 9999;

	sigqueue(3882,SIGUSR1,val);

	while(1);

	return 0;
}


