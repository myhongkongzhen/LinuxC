#include <stdio.h>

int main(){
	char a[10] = {'a','b','c','d','o','.','m','l','e','d'};
	printf("%s \n",a);
	char s[10] = {'a','b','c','d','\0','.','m','l','e','d'};
	printf("%s \n",s);
	printf("%s \n",s+2);
	printf("%s \n",s+6);
	char str[100];
	printf("please input string : ");
	scanf("%s\n",&str);
	printf("---%s\n",str);
	scanf("%*[^\n]%*c");
	printf("please input string : ");
	gets(str);
	printf("====%s\n",str);
	puts(str);
	printf("00000000000000000000000\n");
	printf(str);
	printf("\n");
	return 0;
}



