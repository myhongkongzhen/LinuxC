/*
 * =====================================================================================
 *
 *       Filename:  19-qq-client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 21时58分04秒
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
#include <signal.h>
#include <fcntl.h>
#include <curses.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

WINDOW* win,* wmsg;
int fd;
struct sockaddr_in addr;
void handle(int s){
	if(s == SIGCHLD){
		pid_t pid = wait(NULL);
		printf("%d exit..\n",pid);
	} else{
		printf("client child process exit......\n");
		exit(0);
	}
}

int initsock(){
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1){
		printf("socket error:%m\n");
		return -1;
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8866);
	inet_aton("192.168.137.3",&addr.sin_addr);
	int r = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r == -1){
		printf("socket bind error:%m\n");
		close(fd);
		return -1;
	}
	return 0;
}
void iniui(){
	initscr();

	win = derwin(stdscr,LINES-3,COLS,0,0);
	wmsg = derwin(stdscr,3,COLS,LINES-3,0);

	box(win,'|','-');
	box(wmsg,'|','-');

	refresh();
	wrefresh(win);
	wrefresh(wmsg);
}
void destroy(){
	close(fd);
	endwin();
}

void showmsg(){
	int line = 1;
	while(1){
		char buf[256];
		int r = recv(fd,buf,255,0);
		buf[r] = 0;
		mvwaddstr(win,line,1,buf);
		if(line++>=(LINES-3)){
			line = 1;
			box(win,0,0);
		}
		refresh();
		wrefresh(wmsg);
		wrefresh(win);
	}
}

void sendwmsg(){
	while(1){
		char buf[256];
		mvwgetstr(wmsg,1,1,buf);
		send(fd,buf,strlen(buf),0);
		wclear(wmsg);
		box(wmsg,0,0);
		refresh();
		wrefresh(wmsg);
		wrefresh(win);
	}
}

int main(){
	signal(SIGCHLD,handle);
	signal(SIGINT,handle);
	iniui();
	int r = initsock();
	if(r == -1){
		exit(-1);
	}

	if(fork()){
		sendwmsg();
	}else{
		showmsg();
	}

	destroy();
	return 0;
}


