#include <stdio.h>

int main(){
	//程序中避免野指針，盡量使用空指針
	int* p;//野指針
	printf("p = %p\n",p);
	int* q = 0;//NULL空指針
	printf("q = %p\n",q);
#define T int*
	union{
		T x;	
		char b[sizeof(T)];
	}u;
	u.x = q;
	int i ;
	for(i = 0 ; i < sizeof(T) ; i ++){
		printf("%d ",u.b[i]);
	}
	printf("\n");
	//野指針可能導致段錯誤
	//*p = 100;
	int a[5] = {11,22,33,44,55};	
	p = a;
	for(i = 0 ; i < 5; i ++)
		printf("%d ",a[i]);
	printf("\n");
	for(i = 0 ; i < 5; i ++)
		printf("%d ",*(a+i));
	printf("\n");
	for(i = 0 ; i < 5; i ++)
		printf("%d ",p[i]);
	printf("\n");
	for(i = 0 ; i < 5; i ++)
		printf("%d ",*(p+i));
	printf("\n");
	//*((p+2)+1) ===> 44
	printf("%d\n",(p+2)[1]);
	q = p +3;
	//1[q] == q[1] ===> 55
	printf("%d\n",1[q]);
	printf("p = %p\nq = %p\nq-p = %d\n",p,q,q-p);
		
	//11,12,13,14,15
	for(i = 0 ; i < 5; i ++)
		//*取值符大於+加號運算符
		printf("%d ",*p+i);
	printf("\n");

	//11,22,33,44,55
	for(i = 0 ; i < 5; i ++)
		//++的運算級大於*號，但是因為是後加加，
		//因此取得是P的舊值
		printf("%d ",*p++);
	printf("\n");

	for(i = -5 ; i < 0; i ++)
		printf("%d ",p[i]);
	printf("\n");

	for(i = 0 ; i < 5; i ++)
		printf("%d ",*--p);
	printf("\n");

	return 0;
}


