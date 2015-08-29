/*
 * =====================================================================================
 *
 *       Filename:  5-02scandir.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 16时44分42秒
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
#include <string.h>
#include <sys/types.h>

//int mysort(const struct dirent** d1,const struct dirent** d2){
int mysort(const void* d1,const void* d2){
	return -alphasort(d1,d2);
}

int myfilter(const struct dirent* d){
	return memcmp(d->d_name,".",1);
}

int main(){

	struct dirent** de;
	int r;
	int i;
	r = scandir("/home/wzz",&de,myfilter,mysort);
	//r = scandir("/home/wzz",&de,myfilter,NULL);
	printf("sub dir num:%d\n",r);

	for(i = 0 ; i < r; i ++){
		printf("%s\n",de[i]->d_name);
	}

	printf("---------------------------------\n");
	r = scandir("/home/wzz",&de,myfilter,alphasort);
	while(*de){
		printf("%s\n",(*de++)->d_name);
	}

	return 0;
}

