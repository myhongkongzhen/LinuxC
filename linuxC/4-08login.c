/*
 * =====================================================================================
 *
 *       Filename:  4-08login.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月21日 10时57分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void init();
void drawlogin();
void destroy();

int main(){

	init();
	drawlogin();
	destroy();
	return 0;
}

void drawlogin(){
	char* heads = "login demo system";
	char* user = "user[         ]";
	char* pass= "pass[         ]";
	char* copyright= "design by zzw";

	box(stdscr,'|','-');
	attron(A_BOLD);
	mvaddstr(3,(COLS-strlen(heads))/2,heads);
	attroff(A_BOLD);
	mvaddstr(6,(COLS-strlen(user))/2,user);
	mvaddstr(8,(COLS-strlen(pass))/2,pass);
	mvaddstr(12,(COLS-strlen(copyright))/2+14,copyright);

	refresh();

}

void destroy(){
	getch();
	endwin();
}

void init(){
	initscr();
}

