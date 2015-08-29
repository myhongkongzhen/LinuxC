#include <stdio.h>

int main(){
	//在只讀存儲區域中
	char* names[5] = {"tani","jun","mizu","aran","kei"};
	int i = 0 ;
	for(; i < 5 ; i ++){
		printf("---%s----\n",*(names+i));	
	}

	const int a = 10,b = 30,c = 2;
	//指針數組做排序的工作
	const int* p[3] = {&a,&b,&c};
	for(i = 0 ; i < 3 ; i ++){
		printf("%d ",*p[i]);	
	}
	printf("\n");

	//指針數組做排序的工作
	int j;
	for(i = 0 ; i < 3 ; i++){
		for(j = i ; j < 3; j ++){
			if(*p[j]<*p[i]){
				//只是交換地址，但每個地址包含的值，不改變
				const int* tmp = p[j];	
				p[j] = p[i];
				p[i] = tmp;

			}
		}	
	}

	for(i = 0 ; i < 3 ; i ++){
		printf("%d ",*p[i]);	
	}
	printf("\n");
	return 0;
}



