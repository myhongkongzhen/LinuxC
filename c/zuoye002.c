#include <stdio.h>

int main(){
	int y = 0 ;
	int m = 0 ;
	int d = 0 ;
	int cnt = 0;
	int day = 30;
	int days = 0;
	do{
		printf("Please year-month-day : ");
		cnt = scanf("%d-%d-%d",&y,&m,&d);
		if((y % 400 != 0) || ((y % 4 == 0) && (y % 100 != 0))){
			if(d !=28)
				continue;
		}
	}while(cnt != 3 || ( m < 1|| m >12 || d < 1));

	int j ;
	for(j = 1 ; j < m; j++){
		/**
		  if(j % 2 != 0){
		  days += 31;	
		  }else {
		  days += 30;	
		  }	
		  */
		switch(j){
			case 1 : 	
			case 3 : 	
			case 5 : 	
			case 7 : 	
			case 8 : 	
			case 10 : 	
			case 12 : 	
				days += 31;
				break;
			case 4 : 	
			case 6 : 	
			case 9 : 	
			case 11 : 	
				days +=30;
				break;
			default:
				if((y % 400 != 0) || ((y % 4 == 0) && (y % 100 != 0))){
					days += 28;
				}else{
					days += 29;
				}
				break;
		}
	}

	days += d;
	printf("days of year : %d\n",days);

	return 0;
}



