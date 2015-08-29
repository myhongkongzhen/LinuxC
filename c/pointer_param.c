#include <stdio.h>

void swap(int* a,int* b){
	int t = *a;
	*a  = *b;
	*b = t;
}

int main(){
	int a = 10, b = 20;
	printf("a = %d,b = %d\n",a,b);
	//int* p = &a , * q = &b;
	int* p = &a;	
	int* q = &b;
	swap(p,q);
	//swap(&a,&b);
	printf("a = %d,b = %d\n",a,b);
	return 0;
}


