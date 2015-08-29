/*
 * =====================================================================================
 *
 *       Filename:  4-06addch.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 09时52分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <curses.h>

int main(){

	initscr();
	if(has_colors() == TRUE){
		start_color();
		//------------前景色,--背景色
		//支持8套顏色，1-8
		init_pair(1,COLOR_RED,COLOR_WHITE);
		init_pair(2,COLOR_BLUE,COLOR_GREEN);
		init_pair(3,COLOR_WHITE,COLOR_BLUE);
		//bkgd('a'|COLOR_PAIR(3));
		bkgd(COLOR_PAIR(3));
	}

	box(stdscr,'|','-');

	mvaddch(1,10,'A'|A_BOLD);
	mvaddch(3,10,'A'|A_BLINK|A_UNDERLINE|COLOR_PAIR(2));
	mvaddch(5,10,'A'|A_REVERSE|COLOR_PAIR(1));
	mvaddch(7,10,'A'|A_DIM);
	mvaddch(8,10,ACS_PI);

	attron(COLOR_PAIR(1));
	mvaddstr(6,20,"Hello 純!");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2)|A_BLINK);
	mvaddstr(10,20,"塔尼!");
	attroff(COLOR_PAIR(2)|A_BLINK);

	mvprintw(9,10,"line:%d,v:%d",LINES,COLS);

	getch();
	endwin();

	return 0;
}

