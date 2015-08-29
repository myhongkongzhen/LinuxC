#include <stdio.h>

void print(int a[],int n){
	printf("--%p\n",a);
	int i;
	for(i = 0 ; i < n ; i++){
		printf("%d ",a[i]);	
	}
	printf("\n");
}

int main(){
	int a[5] = {11,22,33,44,55};
	printf("==%p\n",a);
	int b[7] = {6,7,8,9,10,4};
	printf("=-=%p\n",b);
	print(a,5);
	print(b,7);
	return 0;
}



