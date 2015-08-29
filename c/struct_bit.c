#include <stdio.h>

typedef struct goods{
	char name[17]; //18
	double price; //8
	char special;//1
	int num; //4
	short sale;//2
	//18+8+1+4=31+2=33+3+4=40;
	//18+8+2+1+3+4=36;
}goods;

typedef struct {
	char name[17]; //18
	double price; //8
	char special;//1
	short sale;//2
	int num; //4
	//18+8+1+4=31+2=33+3+4=40;
	//18+8+2+1+3+4=36;
}goodsa;

typedef struct {
	char name[17]; //18
	char special;//1
	short sale;//2
	double price; //8
	int num; //4
	//18+8+1+4=31+2=33+3+4=40;
	//18+8+2+1+3+4=36;
}goodsb;

int main(){
	goods g[2];
	//對齊與補齊
	printf("%d\n",sizeof(goods));
	printf("%d\n",sizeof(goodsa));
	printf("%d\n",sizeof(goodsb));
	return 0;
}



