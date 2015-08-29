/*
 * =====================================================================================
 *
 *       Filename:  5-04system.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 17时31分13秒
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
#include <sys/wait.h>
#include <sys/types.h>

int main(){

	int r ;
	printf("%d\n",getpid());
	//r = system("ls -l");
	r = system("./maint");
	//printf("%d\n",r>>8&255);
	printf("%d\n",WEXITSTATUS(r));
	return 0;
}

