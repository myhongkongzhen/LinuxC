#include <stdio.h>
#include "check.h"
#include "convert.h"

int main(){
	char c;
	printf("please input str : \n");
	do{
		scanf("%c",&c);	
		if(isLower(c)){
			printf("%c", toUpper(c));	
		}else if(isNum(c)){
			tocn(c);	
		}else{
			printf("%c",c);	
		}
	}while(c != '\n');
	return 0;
}


