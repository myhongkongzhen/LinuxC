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
#include <sched.h>

typedef struct achar{
	int x;
	int y;
	int speed;
	char a;
}achar;

pthread_t t[26];
pthread_t tid;
pthread_mutex_t m;
achar a[26];
int stop = 1;

void* run(void* d){
	int id;
	static idx = -1;
	id = ++idx;
	while(stop){
		pthread_mutex_lock(&m);
		a[id].y += a[id].speed;
		if(a[id].y >= LINES){
			a[id].y = rand()%(LINES/4);
		}
		pthread_mutex_unlock(&m);
		sched_yield();
		usleep(100000);
	}
}

void* update(void* d){
	int i;
	while(stop){
		//	pthread_mutex_lock(&m);
		erase();
		for(i = 0 ; i < 26 ; i ++){
			mvaddch(a[i].y,a[i].x,a[i].a);
		}
		refresh();
		usleep(10000);
		//	pthread_mutex_unlock(&m);
	}
}

int main(){

	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr,TRUE);

	int i;
	for(i = 0 ; i < 26 ; i ++){
		a[i].x = rand()%COLS ;
		a[i].y = rand()%(LINES/4);
		a[i].speed = 1 + rand()%6;
		a[i].a = 65 + rand()%26;
	}

	pthread_mutex_init(&m,0);
	pthread_create(&tid,0,update,0);

	for(i = 0 ; i < 26 ; i ++){
		pthread_create(&t[i],0,run,0);
	}

	getch();
	stop = 0;
	for(i = 0 ; i < 26 ; i ++){
		pthread_join(t[i],(void**)0);
	}
	pthread_join(tid,(void**)0);
	pthread_mutex_destroy(&m);
	endwin();

	return 0;
}

