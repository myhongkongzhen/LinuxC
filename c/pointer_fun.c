#include <stdio.h>

char* fun(){
	//不要返回局部變量的地址
	//除非加上static，變成靜態局部變量，不被釋放
	char c = '%';
	return &c;
}

int main(){
	//懸空指針，指向一個可能已經釋放了的地方
	char * p = fun();
	printf("%c\n",p);
	return 0;
}


