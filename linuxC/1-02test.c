/*
 * =====================================================================================
 *
 *       Filename:  1-02test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 05时57分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
//unix standard unix標準頭文件
#include <unistd.h>

int main(){
	printf("%d\n",getpid());
	while(1);
	return 0;
}

