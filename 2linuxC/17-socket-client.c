/*
 * =====================================================================================
 *
 *       Filename:  16-socket-server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 18时07分22秒
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
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(){

	int cs = socket(AF_INET,SOCK_STREAM,0);
	if(cs == -1){
		printf("socket create : %m\n");
		exit(-1);
	}
	printf("create socket succecs......\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8686);
	inet_aton("192.168.137.3",&addr.sin_addr);
	//addr.sin_addr.s_addr = 0;	

	int r = connect(cs,(struct sockaddr*)&addr,sizeof(addr));
	if(r == -1){
		printf("socket connet : %m\n");
		close(cs);
		return -1;
	}
	printf("connet socket succecs......\n");

	char buf[100];
	while(1){
		r = read(cs,buf,sizeof(buf));
		if(r == -1){
			printf("socket read: %m\n");
			break;
		}
		if(r == 0){
			printf("socket closed: %m\n");
			break;
		}
		if(r > 0){
			buf[r] = '\0';
			printf("::%s\n",buf);
		}
	}

	close(cs);

	return 0;
}


