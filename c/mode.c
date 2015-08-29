#include <stdio.h>

typedef struct{
	//位段
	unsigned char userread:1;
	unsigned char userwrite:1;
	unsigned char userexecute:1;

	unsigned char groupread:1;
	unsigned char groupwrite:1;
	unsigned char groupexecute:1;

	unsigned char otherread:1;
	unsigned char otherwrite:1;
	unsigned char otherexecute:1;
}mode;

int main(){
	mode m={1,1,0,1,0,0,1,0,0};
	printf("%d\n",sizeof(m));
	printf("%d%d%d,%d%d%d,%d%d%d\n",
			m.userread,m.userexecute,m.userwrite,m.groupread,
			m.groupexecute,m.groupwrite,m.otherread,m.otherexecute,
			m.otherwrite);
	return 0;
}


