/*
 * =====================================================================================
 *
 *       Filename:  17-01demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月28日 22时46分05秒
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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>

int main(){

	struct ifreq ifcg[10];
	struct ifconf ifc;
	ifc.ifc_len = sizeof(ifcg);
	ifc.ifc_req = ifcg;
	int fd;

	int r;
	int count;

	fd = socket(AF_INET,SOCK_DGRAM,0);
	r = ioctl(fd,SIOCGIFCONF,&ifc);

	count = ifc.ifc_len/sizeof(struct ifreq);
	printf("interface count : %u\n",count);
	int i;	
	for( i  = 0 ; i < count ; i ++){
		struct ifreq ifr;
		struct sockaddr_in* ddr;
		printf("%s\n",ifcg[i].ifr_name);
		memcpy(ifr.ifr_name,ifcg[i].ifr_name,
				strlen(ifcg[i].ifr_name));
		r = ioctl(fd,SIOCGIFDSTADDR,&ifr);
		ddr = (struct sockaddr_in*)&ifr.ifr_dstaddr;
		printf(" |-%s\n",inet_ntoa(ddr->sin_addr));

		r = ioctl(fd,SIOCGIFBRDADDR,&ifr);
		ddr = (struct sockaddr_in*)&ifr.ifr_broadaddr;
		printf(" |-%s\n",inet_ntoa(ddr->sin_addr));

		r = ioctl(fd,SIOCGIFNETMASK,&ifr);
		ddr = (struct sockaddr_in*)&ifr.ifr_netmask;
		printf(" |-%s\n",inet_ntoa(ddr->sin_addr));

		r = ioctl(fd,SIOCGIFMTU,&ifr);
		printf(" |-%d\n",ifr.ifr_mtu);
	}

	return 0;
}

