/*
 * =====================================================================================
 *
 *       Filename:  9-03inet.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月23日 15时47分36秒
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

	/* 
	 * in_addr_t nip = 192<<24 | 168<<16 | 137<<8 | 3;
	 * 	char *ip = "192.168.137.3";
	 * 	//	char cip[4] = {192,168,137,3};
	 * 	//	int nip2 = (int*)cip;
	 * 
	 * 	struct in_addr sip ; 
	 * 	int myip;
	 * 
	 * 	sip.s_addr = nip;
	 * 	printf("%s\n",inet_ntoa(sip));
	 * 	printf("nip : %u\n",nip);
	 * 
	 * 	myip = inet_addr(ip);
	 * 	printf("%u\n",myip);
	 * 
	 * 	printf("%hhu.%hhu.%hhu.%hhu\n",
	 * 			myip>>24 & 255,myip>>16 & 255,
	 * 			myip>>8 & 255,myip>>0 & 255);
	 * 
	 */

	char *ip = "10.18.17.3";
	struct in_addr addr;
	in_addr_t net;
	in_addr_t host;
	struct in_addr tmp;

	inet_aton(ip,&addr);
	net = inet_lnaof(addr);
	host = inet_netof(addr);

	tmp.s_addr = net;
	printf("%s\n",inet_ntoa(tmp));

	tmp.s_addr = host;
	printf("%s\n",inet_ntoa(tmp));


	return 0;
}

