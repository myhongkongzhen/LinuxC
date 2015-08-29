#include <stdio.h>

//函數聲明
void clear();

int main(){
	char name[20];
	char gender;
	printf("please input name : ");
	scanf("%s",name);
	clear();
	printf("please input gender(M/F) : ");
	scanf(" %c",&gender);
	printf("name : %s , gender : %c \n",name,gender);
	return 0;
}

void clear(){
	scanf("%*[^\n]");
	scanf("%*c");
}

