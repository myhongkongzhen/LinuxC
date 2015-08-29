#include <stdio.h>

int main(){

	int i = 0;
	int d = 0;
	do{
		printf("Please input num (1~9): ");	
		d = scanf("%d",&i);
		scanf("%*[^\n]%*c");
	}while((d != 1 )||i<1||i>9);

	int m,n ;
	for(m = 1 ; m <= i ; m++){
		for(n = 1; n <= m ; n ++){
			printf("%d*%d=%d%c",n,m,n * m,(n!=m ? ',':'\n'));
		}
	}
	return 0;
}




