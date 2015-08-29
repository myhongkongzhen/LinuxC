/*
 * =====================================================================================
 *
 *       Filename:  10-05qq.c
 *
 *    Description:  聊天程序客戶端 
 *
 *        Version:  1.0
 *        Created:  2014年08月25日 09时33分29秒
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
#include <string.h>
#include <curses.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

WINDOW* winfo,* wmsg;
int fd;
int r;
struct sockaddr_in dr;

int initSocket();
void initUI();
void destroy();
void handle(int s);

int main(){

	signal(SIGCHLD,handle);
	r = initSocket();
	if(r == -1){
		printf("init socket :%m\n");
		exit(-1);
	}
	printf("Init socket success.....\n");

	initUI();

	if(fork()){
		//input ,send
		char buf[256];	
		while(1){
			r = mvwgetstr(wmsg,1,1,buf);
			send(fd,buf,strlen(buf),0);
			wclear(wmsg);
			box(wmsg,'|','-');
			refresh();
			wrefresh(wmsg);
		}
	}else{
		//receive ,show
		char buf[256];
		int line = 1;
		while(1){
			r = recv(fd,buf,255,0);
			if(r == -1)break;
			buf[r] = 0;
			mvwaddstr(winfo,line,1,buf);
			line++;

			if(line >= (LINES-6)){
				wclear(winfo);
				line = 1;
				box(winfo,'|','-');
			}

			wmove(wmsg,1,1);
			touchwin(wmsg);

			refresh();
			wrefresh(winfo);
			wrefresh(wmsg);

		}
		exit(0);
	}

	destroy();

	return 0;
}

void handle(int s){
	wait(&s);
	destroy();
	exit(-1);
}

void destroy(){

	getchar();
	close(fd);
	endwin();
}

void initUI(){
	initscr();
	winfo = derwin(stdscr,(LINES-3),COLS,0,0);
	wmsg = derwin(stdscr,3,COLS,(LINES-3),0);

	keypad(stdscr,TRUE);
	keypad(winfo,TRUE);
	keypad(wmsg,TRUE);

	box(winfo,'|','-');
	box(wmsg,'|','-');

	refresh();
	wrefresh(winfo);
	wrefresh(wmsg);
}

int initSocket(){
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1){
		return -1;
	}

	dr.sin_family = AF_INET;
	dr.sin_port = htons(6688);
	dr.sin_addr.s_addr = inet_addr("192.168.137.3");

	r = connect(fd,(struct sockaddr*)&dr,sizeof(dr));
	if(r == -1){
		close(fd);
		return -1;
	}

	return 0;
}

