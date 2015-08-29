#include <stdio.h>
#include <stdarg.h>

int max(int cnt,...){
	//保存可變長參數表
	va_list v;
	//用v保存參數cnt后的不定參數表
	va_start(v,cnt);
	int i ;
	//從參數表中取出int類型的參數
	int max  = va_arg(v,int);
	for(i = 1 ; i < cnt ; i ++){
		//從參數表中取出int類型的參數
		int data = va_arg(v,int);
		if(data > max)
			max = data;
	}
	//釋放可變長參數表
	va_end(v);
	return max;
}

void printchar(int cnt,...){
	va_list v;
	va_start(v,cnt);
	int i;
	for(i = 0 ; i < cnt  ; i ++){
		//類型自動提升，char，short提升為int
		//float，double提升為double
		printf("%c ",va_arg(v,int));
	}
	printf("\n");
}

void printstring(int cnt,...){
	va_list v;
	va_start(v,cnt);
	int i;
	for(i = 0 ; i < cnt  ; i ++){
		//一次從參數表中讀取字符串
		printf("%s ",va_arg(v,char*));
	}
	printf("\n");
}

int main(){
	printf("%d \n",max(3,1,2,3));
	printf("%d \n",max(4,31,89,2,3));
	printf("%d \n",max(5,32,68,21,92,23));
	printchar(3,'a','b','c');
	printchar(5,'e','f','g','i','l');
	printstring(3,"hello","world","haha");
	printstring(2,"lala","hoho");
	return 0;
}




