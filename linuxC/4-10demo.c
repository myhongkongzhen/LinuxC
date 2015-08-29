/*
 * =====================================================================================
 *
 *       Filename:  4-10demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 11时28分16秒
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
	int ch;
	int x = 5,y = 5;

	initscr();
	//防止回顯
	noecho();
	//對某個窗口開啟功能鍵
	keypad(stdscr,TRUE);
	curs_set(0);
	mvaddch(y,x,'A');
	while(1){
		ch = getch();
		//mvaddch(y,x,' ');
		//erase();和上面清屏方法等效	
		clear();
		switch(ch){
			case KEY_UP:
				y--;
				break;
			case KEY_DOWN:
				y++;
				break;
			case KEY_LEFT:
				x--;
				break;
			case KEY_RIGHT:
				x++;
				break;
		}
		mvaddch(y,x,'A');
		refresh();
	}

	endwin();
	return 0;
}

