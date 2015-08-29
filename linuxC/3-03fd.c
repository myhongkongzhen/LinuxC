/*
 * =====================================================================================
 *
 *       Filename:  3-03fd.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月13日 00时24分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <unistd.h>

int main(){
	//	printf("%d\n",getpid());
	//	while(1);
	//	0:輸入
	int r = write(0,"hello\n",6);
	printf("%d\n",r);
	//  1:輸出
	write(1,"world\n",4);
	//  2:錯誤輸出
	write(2,"mizu\n",8);

	int a = 39;
	write(1,&a,4);

	char buf[32];
	r = read(0,buf,30);
	printf("------%d\n",r);
	if(r > 0){
		buf[r] = 0;
		printf("::%s\n",buf);
	}else if(r == 0){
		printf("ctrl+d");
	}else if(r == -1){
		printf("ERROR");
	}
	return 0;
}

