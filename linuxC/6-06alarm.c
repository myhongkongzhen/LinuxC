/*
 * =====================================================================================
 *
 *       Filename:  6-06alarm.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 19时14分00秒
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
#include <signal.h>
#include <sys/time.h>

void deal(int s){
	printf("get up!\n");
}

int main(){
	struct itimerval v = {0};
	signal(SIGALRM,deal);

	//定時器
	//3秒后開始，每2秒觸發定時器
	v.it_value.tv_sec = 3;
	v.it_interval.tv_sec = 2; 

	setitimer(ITIMER_REAL,&v,0);

	//alarm(5);//延時器,只觸發一次
	while(1){
		printf("sleep...(%d).\n",getpid());
		sleep(1);
	}
	return 0;
}

