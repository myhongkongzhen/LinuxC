#include <stdio.h>

void hano(char from,int n,char to,char emp){
	if(n > 0){
		hano(from,n-1,emp,to);
		printf("%d from %c to %c\n",n,from,to);
		hano(emp,n-1,to,from);
	}
}

int main(){
	hano('a',10,'b','c');
	return 0;
}

