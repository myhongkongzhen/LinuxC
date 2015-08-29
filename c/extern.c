#include <stdio.h>

//全局變量外部文件定義，這裡只做聲明，不受文件限制
extern char w[3][10];
extern char e[3][10];

char* weekday(int n){
	return w[n];
}

char* wd(int n){
	//靜態局部變量，只初始化一次，出範圍仍然不釋放
	static char w[3][10]={"死","吧","你"};
	return w[n];
}

int counter(){
	static int cnt = 0;
	return ++cnt;
}

int main(){
	printf("%s\n",weekday(2));
	printf("%s\n",wd(2));
	int i ;
	for(i = 0;i<10; i++){
		printf("%d  ",counter());	
	}
	printf("\n");

	return 0;
}


