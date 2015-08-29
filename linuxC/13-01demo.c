/*
 * =====================================================================================
 *
 *       Filename:  13-01demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月27日 13时03分25秒
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
#include <pthread.h>
#include <curses.h>
#include <math.h>

typedef struct achar{
	int x;
	int y;
	int speed;
	char a;
}achar;

pthread_t t[26];
pthread_mutex_t m;

void* run(void* d){
	achar a;
	a.x = rand()%COLS ;
	a.y = rand()%(LINES/4);
	a.speed = 1 + rand()%3;
	a.a = 65 + rand()%26;
	while(1){
		a.y += a.speed;
		if(a.y >= LINES){
			a.y = rand()%(LINES/4);
		}
		pthread_mutex_lock(&m);
		mvaddch(a.y,a.x,a.a);
		refresh();
		pthread_mutex_unlock(&m);
		usleep(10000);
	}
}

int main(){

	initscr();
	pthread_mutex_init(&m,0);

	int i;
	for(i = 0 ; i < 26 ; i ++){
		pthread_create(&t[i],0,run,0);
	}

	getch();
	pthread_mutex_destroy(&m);
	endwin();

	return 0;
}

