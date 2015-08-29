/*
 * =====================================================================================
 *
 *       Filename:  6-05kill.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 19时04分43秒
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
#include <signal.h>

int main(){
	while(1){
		kill(5114,SIGINT);
		sleep(2);
	}
	return 0;
}

