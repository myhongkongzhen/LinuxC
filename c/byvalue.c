#include <stdio.h>

void swap(int,int);

int main(){
	int m = 10;
	int n = 30;
	printf("m=%p,n=%p\n",&m,&n);
	printf("===%d,%d\n",m,n);
	swap(m,n);
	printf("==%d,%d\n",m,n);
	return 0;
}

//值傳遞
void swap(int a ,int b){
	printf("a=%p,b=%p\n",&a,&b);
	printf("---%d,%d\n",a,b);
	int t = a;
	a = b;
	b = t;
	printf("--%d,%d\n",a,b);
}

