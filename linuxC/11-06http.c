/*
 * =====================================================================================
 *
 *       Filename:  11-06http.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月26日 18时30分06秒
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
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(){

	int fd;
	struct sockaddr_in dr;
	char strreq[1024];
	char buf[10*1024];
	int r;

	//1.create socket
	fd = socket(AF_INET,SOCK_STREAM,0);

	//2.connect server
	dr.sin_family = AF_INET;
	dr.sin_port = htons(80);
	dr.sin_addr.s_addr = inet_addr("192.168.137.3");
	r = connect(fd,(struct sockaddr*)&dr,sizeof(dr));

	//3.construct http get string
	sprintf(strreq,
			"GET /index.php HTTP/1.1\r\n"
			"Host : 192.168.137.3:80"
			"User-Agent : Mozilla/5.0\r\n"
			"Accept : text/plain,text/html,text/xml\r\n"
			"Accept-Language : zh-cn\r\n"
			"Accept-Charset : utf-8\r\n"
			"Keep-Alive : 300\r\n"
			"Connection : keep-alive\r\n"
			"\r\n");

	//4.send http get string
	r = send(fd,strreq,strlen(strreq),0);

	//5.wait server recv
	while(1){
		r = recv(fd,buf,1023,0);
		if(r <= 0){
			break;
		}
		buf[r] = 0;
		printf("----------------------------\n");
		printf("%s\n",buf);
		printf("----------------------------\n");
	}

	close(fd);

	return 0;
}


