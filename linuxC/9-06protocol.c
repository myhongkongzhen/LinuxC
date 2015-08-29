/*
 * =====================================================================================
 *
 *       Filename:  9-06protocol.c
 *
 *    Description:   
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 14时52分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <netdb.h>
#include <sys/utsname.h>

int main(){

	struct protoent* ent;
	ent = getprotobyname("udp");
	printf("%s : %d\n",ent->p_name,ent->p_proto);

	struct utsname usn;
	uname(&usn);
	printf("%s\n",usn.machine);
	printf("%s\n",usn.nodename);
	printf("%s\n",usn.release);
	printf("%s\n",usn.sysname);
	printf("%s\n",usn.version);
	printf("%s\n",usn.domainname);

	return 0;
}

