#include <stdio.h>
#include <string.h>

int main(){
	char a[100] = "hello world!";
	printf("%d\n",sizeof("hello world!"));
	//複製字符串
	strcpy(a," good afternoon!");
	puts(a);
	//追加字符串
	strcat(a," dear friends!");
	puts(a);
	//計算字符串長度，只能計算字符串，計算結果不包括\0
	printf("%d,%d\n",sizeof(a),strlen(a));
	//查找某個字符，返回找到的字符地址，未找到返回null
	//從左向右查詢
	printf("%p\n",strchr(a,'o'));
	//從右向左查詢
	printf("%p\n",strrchr(a,'o'));
	printf("%s\n",strchr(a,'r'));
	//段錯誤
	printf("%s",strchr(a,'k'));
	//查找子串
	printf("%s\n",strstr(a,"ie"));
	printf("===========%s\n",a);
	//字符串比較大小
	int n = strcmp(a,"good afternoon");
	printf("%p,%p\n",a,"good afternoon");
	if(!n)
		printf("相等\n");
	else if(n == -1)
		printf("數組a小\n");
	else printf("數組a大\n");
	return 0;
}


