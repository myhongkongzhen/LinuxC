/*
 * =====================================================================================
 *
 *       Filename:  12-02demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月26日 21时29分06秒
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
#include <curses.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

WINDOW* wn;
WINDOW* wt;

pthread_t tn; 
pthread_t tt; 

pthread_mutex_t m;

void* shownum(void *data){
	int num;
	while(1){
		num = rand()%10000000;
		pthread_mutex_lock(&m);
		mvwprintw(wn,1,2,"%d",num);
		refresh();
		wrefresh(wn);
		pthread_mutex_unlock(&m);
		usleep(100000);
	}
	return 0;
}

void* showtime(void *data){
	time_t ti;
	struct tm* t;
	while(1){
		ti = time(0);
		t = localtime(&ti);
		pthread_mutex_lock(&m);
		mvwprintw(wt,1,2,"%02d:%02d:%02d",
				t->tm_hour,t->tm_min,t->tm_sec);
		refresh();
		wrefresh(wt);
		pthread_mutex_unlock(&m);
		sleep(1);
	}
	return 0;
}

int main(){

	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr,TRUE);

	wn = derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	wt = derwin(stdscr,3,11,1,(COLS-11));

	box(wn,'|','-');
	box(wt,'|','-');

	refresh();
	wrefresh(wn);
	wrefresh(wt);

	pthread_mutex_init(&m,0);

	pthread_create(&tn,0,shownum,0);
	pthread_create(&tt,0,showtime,0);

	//	pthread_join(tn,(void **)0);
	//	pthread_join(tt,(void **)0);

	getch();
	delwin(wt);
	delwin(wn);
	pthread_mutex_destroy(&m);
	endwin();

	return 0;
}

