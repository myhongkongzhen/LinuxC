#include <stdio.h>

int main(){
	int a[5] = {11,22,33,44,55};
	printf("a = %p\n",a);
	int i ;
	for(i = 0 ; i < 5 ; i ++){
		printf("&a[%d] = %p\n",i,&a[i]);	
	}
	for(i = 0 ; i < 5 ; i++)
		printf("a + %d = %p\n",i,a+i);
	return 0;
}


