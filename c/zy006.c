#include <stdio.h>
#include <string.h>

void intToStr(int num,char str[]){
	static int idx = 0;
	int ig = num % 10; 
	str[idx++] = ig + '0';
	num /= 10;
	if(!num) 
		return ;
	intToStr(num,str);
}

void incovert(char str[]){
	int i ;
	int n = strlen(str);
	for(i = 0 ; i < n / 2 ; i ++ ){
		int tmp = str[n - i - 1];	
		str[n - i - 1] = str[i];	
		str[i] = tmp;
	}
}

int main(){
	int n = 334045;
	printf("int : %d \n",n);
	char str[100000];
	intToStr(n,str);
	incovert(str);
	printf("str : %s\n",str);
	return 0;
}


