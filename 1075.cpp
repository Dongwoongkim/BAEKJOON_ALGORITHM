#include <stdio.h>

int n,f;
int i;
int main(){
	
	scanf("%d",&n);
	
	scanf("%d",&f);
	
	// n의 마지막 두자리만 바꿔서 n%f=0 이 되도록 만든다.
	// 1. n의 마지막 두자리를 00으로 바꾼다.
	
	n = n/100 * 100;
	

	// 1부터 99까지 나누어떨어지는수 찾아서 프린트  
	for(i=0;i<=99;i++){
		
		
		if((i+n)%f==0){break;}}
		
		
	if(i<10){printf("0%d",i);}
	else{printf("%d",i);}
	
	return 0; 
}