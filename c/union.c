#include <stdio.h>

//共用同一塊地方
typedef union{
	char i4[4];		
	int net;
}tu;

int main(){
	printf("%d\n",sizeof(tu));
	tu ip ;
	ip.net = 0x12345678;	
	int i;
	for(i = 0 ; i < 4; i ++){
		printf("%d ",ip.i4[i]);	
	}
	printf("\n");
	return 0;
}



