#include <stdio.h>
//當前路徑下尋找頭文件
#include "func_clear.h"

int get(int a,int b){
	int n;
	printf("%d,%d\n",a,b);
	do{
		printf("please input num between%d to %d: ",a,b);	
		if(scanf("%d",&n))
			clear();
	}while(n<a ||n >b);
	return (a+b)/n;
}

int main(){
	int a = get(1,3);
	int b = get(3,300);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}


