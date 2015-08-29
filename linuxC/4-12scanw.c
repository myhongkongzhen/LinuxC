/*
 * =====================================================================================
 *
 *       Filename:  4-12scanw.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 12时35分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <curses.h>

void init();
void drawui();
void dealinput();
void destroy();

int main(){

	init();
	drawui();
	dealinput();
	destroy();
	return 0;
}

void dealinput(){
	int a,b;
	while(1){
		mvaddstr(2,3,"   ");
		mvscanw(2,3,"%d",&a);
		mvaddstr(2,11,"   ");
		mvscanw(2,11,"%d",&b);
		mvaddstr(2,18,"    ");
		mvprintw(2,18,"%d",(a+b));
		refresh();
	}
}

void drawui(){
	mvaddstr(2,2,"[    ]+[    ]=[    ]");
	refresh();
}

void init(){
	initscr();
}

void destroy(){
	endwin();
}

