/*
 * =====================================================================================
 *
 *       Filename:  5-01dir.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 16时04分42秒
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
#include <dirent.h>

int main(){

	DIR* d;
	struct dirent* de;

	d = opendir("/home/wzz/");
	if(d == NULL){
		printf("open dir error:%m\n");
		exit(-1);
	}

	//while((de = readdir(d)) != NULL){
	while(de = readdir(d)){
		printf("%s\t%d\n",de->d_name,de->d_type);
	}

	closedir(d);

	return 0;
}

