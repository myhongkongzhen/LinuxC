/*
 * =====================================================================================
 *
 *       Filename:  4-11addstr.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 11时53分29秒
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

	char name[9];
	int r;

	initscr();

	mvaddstr(4,10,"user : [        ]");
	r = mvgetnstr(4,18,name,8);

	mvprintw(7,10,"-->%s",name);
	refresh();

	getch();

	endwin();

	return 0;
}

