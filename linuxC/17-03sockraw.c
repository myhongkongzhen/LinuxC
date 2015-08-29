/*
 * =====================================================================================
 *
 *       Filename:  17-03sockraw.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月29日 08时23分32秒
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
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <linux/icmp.h>

int main(){

	int fd;
	char buf[2000/* 建議使用:MTU */];
	struct iphdr* iph;
	struct tcphdr* tcph;
	struct icmphdr* icmph;
	struct in_addr dr;
	int isip = 1;
	int r;

	fd = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
	setsockopt(fd,IPPROTO_IP,IP_HDRINCL,&isip,sizeof(int));

	while(1){
		r = read(fd,buf,2000);	
		iph = (struct iphdr*)buf;
		dr.s_addr = iph->saddr;
		printf("ip->%d:%d\n",inet_ntoa(dr),r);
		if(r <= 0) break;
	}

	return 0;
}


