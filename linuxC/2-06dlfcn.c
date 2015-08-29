/*
 * =====================================================================================
 *
 *       Filename:  2-06dlfcn.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 18时52分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <dlfcn.h>

int main(){
	void* handle = dlopen("./lib2-05.so",RTLD_LAZY); 
	void (*fun(int)) = dlsym(handle,"diamond");
	fun(5);
	dlclose(handle);
	return 0;
}

