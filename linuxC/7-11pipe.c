/*
 * =====================================================================================
 *
 *       Filename:  7-11pipe.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 04时19分03秒
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
#include <fcntl.h>

int main(){
	int fd[2];
	int r;
	char buf[20];

	printf("%d\n",getpid());

	r = pipe(fd);

	write(fd[1],"hello",5);
	write(fd[1],"world",5);

	r = read(fd[0],buf,20);
	buf[r] = 0;
	printf("%s\n",buf);

	write(fd[1],"mizu",4);

	r = read(fd[0],buf,20);
	buf[r] = 0;
	printf("%s\n",buf);

	while(1){
	}

	return 0;
}

