#include <stdio.h>

//argc:命令行字符串的個數
//argv:命令行每個字符串的首地址保存在此數組中
int main(int argc , char* argv[]){
	printf("argc = %d\n",argc);
	int i;
	for(i = 0 ; i < argc ; i++){
		printf("%d == %s\n",i,argv[i]);	
	}
	return 0;
}


