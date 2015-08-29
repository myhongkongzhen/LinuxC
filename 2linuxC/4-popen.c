/*
 * =====================================================================================
 *
 *       Filename:  4-popen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 08时37分31秒
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

	FILE* fi = popen("gcc -omain 3-test.c","r");
	int fd = fileno(fi);

	int r;
	char buf[1024];
	printf("==================================\n");
	while((r = read(fd,buf,1022))>0){
		buf[r] = 0;
		printf("::%s\n",buf);
	}
	printf("==================================\n");

	close(fd);
	pclose(fi);

	return ;
}

