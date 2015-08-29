#include <stdio.h>

typedef struct date{
	int year;
	int month;
	int day;
}date;

//只有寫上void，才表示，該函數不接受任何形參
//date input(void){

//參數表空，表形參參數個數類型不定
date input(){
//void input(date d){
	//printf("d of fun input : %p \n",&d);
	date d;
	printf("please input date : \n");
	scanf("%d%d%d",&d.year,&d.month,&d.day);
	//printf("--date : %d-%d-%d\n",d.year,d.month,d.day);
	return d;
}

void print(date d){
	printf("date : %d-%d-%d\n",d.year,d.month,d.day);
}

int main(){
	date d = {2014,7,16};
	printf("d of fun main  : %p \n",&d);
	print(d);
	//參數表空，表形參參數個數類型不定
	d = input(34,'e',"jflds");
	print(d);
	return 0;
}



