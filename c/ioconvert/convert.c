#include <stdio.h>

char toUpper(char c){
	return (c-'a'+'A');
}

char* tocn(char c){
	char num[10][5]={"零","一","二","三","四","五","六","七","八","九"};	

	printf("%s",num[c-'0']);
	return num[(c - '0')];

}


