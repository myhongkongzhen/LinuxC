/*
 * =====================================================================================
 *
 *       Filename:  4-13derwin.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 13时10分14秒
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

	WINDOW* w;

	initscr();
	box(stdscr,'|','-');

	w = derwin(stdscr,4,20,5,3);
	box(w,'|','-');

	refresh();
	wrefresh(w);

	getch();
	endwin();
	return 0;
}

