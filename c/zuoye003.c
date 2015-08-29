#include <stdio.h>

int main(){
	int max = 0 ;
	int min = 0;
	int tmp = 0;
	int i = 0;
	printf("please input 10 num : ");
	scanf("%d%d",&max,&min); 
	if(max < min){
		max = max^min;
		min = max ^min;
		max = max^min;
	}

	for(i = 0 ; i < 8 ;i ++){
		scanf("%d",&tmp); 
		if(tmp > max){
			max = max ^ tmp;	
			tmp = max ^ tmp;
			max = max ^ tmp;
		}else if (tmp < min){
			min= min^ tmp;	
			tmp = min ^ tmp;
			min = min ^ tmp;
		}
	}

	printf("max = %d,min = %d\n",max,min);
	return 0;
}


