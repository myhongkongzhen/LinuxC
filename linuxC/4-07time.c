/*
 * =====================================================================================
 *
 *       Filename:  4-07time.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 10时42分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <curses.h>
#include <time.h>
#include <unistd.h>

void init();
void drawui();
void business();
void destroy();

int main(){

	init();
	drawui();
	business();
	destroy();

	return 0;
}

void business(){
	time_t tt;
	struct tm *t;
	while(1){
		//gettime
		tt = time(0);	
		t = localtime(&tt);
		//showtime
		mvprintw(LINES/2,(COLS-8)/2,
				"%02d:%02d:%02d",
				t->tm_hour,t->tm_min,t->tm_sec);	
		//flush
		refresh();	
		sleep(1);
		//usleep(100000);
	}
}

void drawui(){
	box(stdscr,'|','-');
}

void destroy(){
	endwin();
}

void init(){
	initscr();
}

