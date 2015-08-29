/*
 * =====================================================================================
 *
 *       Filename:  4-09input.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 11时13分25秒
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
	initscr();
	noecho();
	while(1){
		ch = mvgetch(5,10);	
		mvprintw(7,10,"you input : %c(%d)",ch,ch);
	}
	endwin();
	return 0;
}

