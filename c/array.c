#include <stdio.h>

int main(){
	int a[10];
	int i = 0 ;
	for(i = 0 ; i < 10 ; i++){
		printf("%d,",a[i]);	
	}
	printf("\n");
	int num[4] = {3,4,6,2};
	for( i = 0 ; i < 4 ; i++){
		printf("%d ",num[i]);	
	}
	printf("\n");
	int n[4] = {3};
	for( i = 0 ; i < 4 ; i++){
		printf("%d ",n[i]);	
	}
	printf("\n");
	int m[4] = {};
	for( i = 0 ; i < 4 ; i++){
		printf("%d ",m[i]);	
	}
	printf("\n");
	return 0;
}



