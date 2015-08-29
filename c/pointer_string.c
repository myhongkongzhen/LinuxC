#include <stdio.h>
#include <string.h>

int main(){
	char a[100] = {'w','s','\0','l','d'};
	puts(a);
	puts("hello");

	char* p = a;
	printf("%c\n",*p);
	*p = 'm';
	puts(a);

	//只是把字符串的第一個字符的地址賦值給了指針
	p = "world"; //有可能編譯器出現警告
	printf("%c\n",*p);
	//*p = '~'; //段錯誤

	//q保存的是字符常量的地址，但q不是個常量
	//不會通過指針修改其數據
	const char* q = NULL;
	//char const * q = NULL; //與上面的寫法等價

	//只是把字符串的第一個字符的地址賦值給了指針
	q = "ok";//一定是安全的，不會出現段錯誤
	//*q = 'l';//編譯時就會報出錯誤
	puts(q);

	p = a;
	strcpy(a,"NB");
	puts(p);

	//q保存的是字符常量的地址，但q不是個常量
	q = a + 3; //一定是安全的
	puts(q);

	//此時的r是個常量，不可修改
	//以型號*做分割符，*前，字符常量地址，*后，指針是個常量
	//必須初始化
	char * const r  = a+1;
	//r = a;//出錯，不能賦值，只能初始化
	//但是可以修改其字符地址值
	*r = 'A';
	puts(r);

	return 0;
}


