/*
 * =====================================================================================
 *
 *       Filename:  2-read-write.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月31日 21时07分20秒
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

int main(){

	int r = write(0,"hello",5);
	printf("%d\n",r);

	char buf[5];
	r = read(0,buf,3);
	printf("===%d\n",r);

	if(r == 0){
		printf("===%d\n",r);
		buf[r] = 0;
		printf("%s\n",buf);
	}

	if(r > 0){
		buf[r] = 0;
		printf("%s\n",buf);
	}

	if(r == -1){
		printf("error:%m\n");
	}

	return 0;
}

