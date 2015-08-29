#include <stdio.h>

typedef struct goods{
	char name[200];
	double income;
	int chen;
}goods;

int main(){
	goods good[3];
	int i;
	printf("please input 3 goods (name,income,chen):");
	for(i = 0 ; i < 3 ; i ++){
		scanf("%s%lf%d",good[i].name,&good[i].income,&good[i].chen);	
	}

	for(i = 0 ; i < 3 ; i ++){
		printf("name : %s,income : %g,chen : %d == ",good[i].name,good[i].income,good[i].chen);
	}
	printf("\n");

	int j ;
	for(i = 0 ; i < 3 ; i ++){
		for(j = i + 1 ; j < 3 ; j++){
			if(good[i].income < good[j].income){
				goods tmp = good[j];	
				good[j] = good[i];
				good[i] = tmp;
			}	
		}
	}

	for(i = 0 ; i < 3 ; i ++){
		printf("name : %s,income : %g,chen : %d == ",good[i].name,good[i].income,good[i].chen);
	}
	printf("\n");

	for(i = 0 ; i < 3 ; i ++){
		for(j = i + 1 ; j < 3 ; j++){
			if(good[i].chen> good[j].chen){
				goods tmp = good[j];	
				good[j] = good[i];
				good[i] = tmp;
			}	
		}
	}

	for(i = 0 ; i < 3 ; i ++){
		printf("name : %s,income : %g,chen : %d == ",good[i].name,good[i].income,good[i].chen);
	}
	printf("\n");

	return ;
}



