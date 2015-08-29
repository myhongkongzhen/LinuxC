#include <stdio.h>

int main(){
	int a[10];
	int i ;
	printf("please input 10 num : \n");
	for(i = 0 ;  i < 10; i ++){
		scanf("%d",&a[i]);	
	}

	for(i = 0 ; i < 5 ; i ++){
		int tmp = a[i];	
		a[i] = a[10 - i - 1];
		a[10 - i - 1] = tmp;
	}

	for(i = 0 ; i < 10 ; i++){
		printf("%d ",a[i]);	
	}
	printf("\n");

	int j ;
	for(i = 0 ; i < 10 ; i ++){
		for(j  = i+1; j < 10 ;j++){
			if(a[i] > a[j]){
				int tmp = a[j];	
				a[j] = a[i];
				a[i] = tmp;
			}	
		}	
	}

	for(i = 0 ; i < 10 ; i++){
		printf("%d ",a[i]);	
	}
	printf("\n");

	return 0;
}


