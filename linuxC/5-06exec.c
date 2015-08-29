/*
 * =====================================================================================
 *
 *       Filename:  5-06exec.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 19时33分09秒
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

int main(){
	//	printf("::%d\n",getpid());
	//int r = execl("maint","mytest",NULL);
	int r = execlp("ls","ls","-l",NULL);
	//	int r = execl("ls","/usr/bin/ls","-l",NULL);
	printf("::%d\n",r);
	return 0;
}

