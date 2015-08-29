#include <stdio.h>
#include <ctype.h>

int str2int(const char* str,const char** p){
	int r = 0;
	//*str ：字符首地址
	while(isdigit(*str)){
		r = r * 10 + *str - '0';	
		++str;
	}

	*p = str;
	return r;
}

int main(){
	const char* p = NULL;
	int n = str2int("3423lfdslj",&p);
	printf("%d  %s \n",n,p);
	return 0;
}

