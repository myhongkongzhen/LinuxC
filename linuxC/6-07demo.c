/*
 * =====================================================================================
 *
 *       Filename:  6-07demo.c
 *
 *    Description:   
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 19时43分08秒
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
#include <fcntl.h>
#include <signal.h>
#include <math.h>
#include <curses.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

WINDOW* wtime,*wnumb;
int num;
int i = 0;

void showtime(int s){
	time_t tt ;
	struct tm *t;
	if(s == SIGALRM){
		//time(&tt);
		tt = time(0);
		t = localtime(&tt);
		mvwprintw(wtime,1,2,"%02d:%02d:%02d",
				t->tm_hour,t->tm_min,t->tm_sec);
		refresh();
		wrefresh(wtime);
		wrefresh(wnumb);
	}
}

int main(){

	struct itimerval val = {0};

	initscr();


	signal(SIGALRM,showtime);
	val.it_value.tv_sec = 0;
	val.it_value.tv_usec = 1;
	val.it_interval.tv_sec = 1;

	curs_set(0);
	wtime = derwin(stdscr,3,10,1,(COLS-10));
	wnumb = derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);

	box(wtime,'|','-');
	box(wnumb,'|','-');

	setitimer(ITIMER_REAL,&val,0);

	refresh();
	wrefresh(wtime);
	wrefresh(wnumb);

	while(1){
		num = 0;
		for(i = 0 ; i < 7 ; i ++){
			num = num * 10 + rand()%10;
		}
		mvwprintw(wnumb,1,2,"%07d",num);
		refresh();
		wrefresh(wnumb);
		wrefresh(wtime);
		usleep(100000);
	}

	endwin();

	return 0;
}

