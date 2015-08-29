#include <stdio.h>

//            不確定類型時，用void
void showbyte(void* addr,int bytes){
	while(bytes-->0){
		//               每次只取一個字節
		printf("%02x ",*(unsigned char*)addr++);
	}
	printf("\n");
}

int main(){
	int n = 1234567890;
	float f = 1234567890;
	double d = 1234567890;
	short s = 1234567890;//溢出警告
	showbyte(&n,sizeof(n));
	showbyte(&f,sizeof(f));
	showbyte(&d,sizeof(d));
	showbyte(&s,sizeof(s));

	return 0;
}




