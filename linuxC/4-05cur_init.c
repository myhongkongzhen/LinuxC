/*
 * =====================================================================================
 *
 *       Filename:  4-05cur_init.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 08时38分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <ncurses.h>

int main(){

	//初始化終端
	initscr();
	//WINDOW *w = initscr();

	border('a','b','c','d','e','f','g','h');
	//	border(0,0,0,0,0,0,0,0);
	//box(w,'|','-');	
	//box(stdscr,'|','_');	

	mvhline(2,10,'-',30);//指定位置水平線
	mvvline(2,10,'|',4);//指定位置垂直線

	refresh();//刷屏

	getch();

	//釋放終端
	endwin();

	return 0;
}

