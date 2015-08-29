#include <stdio.h>

int main(){
	int n = 0;
	const int bits = sizeof(int)*8;
	unsigned int bit = 1<<bits -1; //0x80000000
	printf("Please input num : ");
	scanf("%d",&n);
	int i;
	for(i = 0 ; i < bits ; i++){
		//printf("%c",n&bit? '1':'0');	
		//	bit >>= 1;
		//	利用符號位實現
		//printf("%c",n<0?'1':'0');
		printf("%d",n<0);	
		n <<= 1;
	}
	printf("\n");
	return 0;
}


