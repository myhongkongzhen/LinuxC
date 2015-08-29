#include <stdio.h>

int main(){
	printf("1:c++");
	printf("2:java");
	printf("3:qie");
	char ch;
	scanf(" %c",&ch);
	switch(ch){
		case 1:
			printf("1....c++");	
			break;
		case 2:
			printf("2.....java");
			break;
		case 3:
			printf("3.....qie");
			break;
		default:
			printf(".......over.....");
	}
	printf("Good bye!");
	return 0;
}


