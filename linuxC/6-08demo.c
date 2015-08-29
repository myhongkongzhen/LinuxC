/*
 * =====================================================================================
 *
 *       Filename:  6-08demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月22日 20时38分05秒
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
#include <curses.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <math.h>

WINDOW* w;
int num,i;
int isstop = 0;

void handle(int s){
	if(s == SIGUSR1){
		if(isstop == 0){
			isstop = 1;
		}else{
			isstop = 0;
		}
	}
}

int main(){

	initscr();

	curs_set(0);

	w = derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	keypad(stdscr,TRUE);
	keypad(w,TRUE);
	noecho();

	box(w,'|','-');
	refresh();
	wrefresh(w);

	if(fork()){
		signal(SIGUSR1,handle);
		while(1){
			if(isstop == 1){
				pause();
			}
			num = 0;
			for(i = 0 ; i < 7 ; i ++){
				num = num*10 + rand()%10;
			}
			mvwprintw(w,1,2,"%07d",num);
			refresh();
			wrefresh(w);
			usleep(100000);
		}
	}else{
		int ch;
		while(1){
			ch = getch();
			if(ch = KEY_ENTER){
				kill(getppid(),SIGUSR1);
			}
		}
	}

	endwin();

	return 0;
}


