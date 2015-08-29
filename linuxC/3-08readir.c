/*
 * =====================================================================================
 *
 *       Filename:  3-05open.c
 *
 *    Description:  結構體數據讀取  
 *
 *        Version:  1.0
 *        Created:  2014年08月20日 09时29分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

	int fd;

	printf("Hello\n");
	write(1,"world\n",6);
	fd = open("/dev/tty",O_WRONLY);
	if(fd == -1){
		printf("error : %m\n");
		exit(1);
	}
	if(isatty(1)){
		write(1,"noreadir\n",9);
	}else{
		write(1,"readir\n",6);
	}
	write(fd,"killer",sizeof("killer")+1);

	close(fd);

	return 0;
}

