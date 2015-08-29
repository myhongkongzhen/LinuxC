/*
 * =====================================================================================
 *
 *       Filename:  17-04arp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月29日 09时11分24秒
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
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>

int main(){

	int fd;
	char buf[2000];
	int r;
	struct ethhdr* eh;
	fd = socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL));

	while(1){
		r = read(fd,buf,2000);
		eh = (struct ethhdr*)buf;
		printf("-->%x\n",ntohs(eh->h_proto));
	}

	return 0;
}

