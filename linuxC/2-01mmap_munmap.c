/*
 * =====================================================================================
 *
 *       Filename:  2-01mmap_munmap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 14时21分39秒
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
#include <sys/mman.h>

int main(){
	int *p = mmap(0,//指定虛擬內存影射的地址，0，由系統指定
			getpagesize(),//指定分配大小，以pagesize整數倍
			PROT_WRITE,//權限
			//PROT_READ,//權限
			//PROT_READ|PROT_WRITE,//權限
			MAP_ANONYMOUS|MAP_SHARED,//影射標識
			0,//只有前面指定文件影射，后兩個參數才有效
			0);
	*p = 20;
	*(p+1) = 30;
	*(p+2) = 40;

	//-------------數組是個常指針,是個常量,指針變量是變量
	printf("%d\n",p[2]);
	munmap(p,getpagesize());
	//munmap(p,4096);
	printf("--%d\n",getpagesize());
	return 0;
}

