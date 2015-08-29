#include <stdio.h>
#include <string.h>

typedef enum gender{MALE,FEMALE} gender;
typedef struct person{
	char name[20];
	gender s;
	int age ;
	//結構體中不允許初始化
	//int age = 0;
	double income;
}person;

int main(){
	person a;
	person b;
	strcpy(a.name ,"zzw");
	a.age = 28;
	a.income = 30.5;
	a.s = FEMALE;
	printf("%s,age : %d,income : %g,%s\n",a.name,a.age,a.income,a.s == MALE ? "帥哥":"美女");
	printf("please input name,gender,age,income: \n");
	char s;
	scanf("%s %c%d%lf",a.name,&s,&a.age,&a.income);
	a.s = (s == 'm' || s == 'M')?FEMALE:MALE;
	printf("%s,age : %d,income : %g,%s\n",a.name,a.age,a.income,a.s == MALE ? "帥哥":"美女");
	return 0;
}


