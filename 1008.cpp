#include<stdio.h>

int main(){
	
	int A,B;
	scanf("%d %d",&A,&B);
	double c;
	
	c = (double) A / B;
	printf("%.9f",c);
	
	return 0;
}