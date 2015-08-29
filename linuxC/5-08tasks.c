/*
 * =====================================================================================
 *
 *       Filename:  5-08tasks.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 20时13分09秒
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
#include <unistd.h>
#include <string.h>
#include <time.h>

WINDOW* wtime,*wnumb;

int main(){
	initscr();

	wtime = derwin(stdscr,3,10,0,(COLS-10));
	wnumb= derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);

	box(wtime,'|','-');
	box(wnumb,'|','-');

	refresh();
	wrefresh(wtime);
	wrefresh(wnumb);

	if(fork()){
		time_t tt;
		struct tm *t;
		//parent showtime	
		while(1){
			tt = time(0);	
			t = localtime(&tt);
			mvwprintw(wtime,1,1,"%02d:%02d:%02d",
					t->tm_hour,t->tm_min,t->tm_sec);
			refresh();
			wrefresh(wtime);
			wrefresh(wnumb);
			sleep(1);
		}	
	}else{
		int num = 0;
		//child number
		int i;	
		while(1){
			//num = rand()%10000000;
			num = 0;	
			for(i = 0 ; i < 7 ; i ++){
				num = num*10+rand()%10;
			}	
			mvwprintw(wnumb,1,2,"%07d",num);
			refresh();
			wrefresh(wtime);
			wrefresh(wnumb);
			usleep(1000000);
		}	
	}


	endwin();
	return 0;
}


