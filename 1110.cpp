#include <stdio.h>

int main(){
	
int A,B,C,Now,NEXT;

int i=0;
	

	scanf("%d",&Now);
	
	while(Now<0||Now>99)
	{ scanf("%d",&Now);
	}
	
	
	
	A=Now/10;  // 현재값 N의 앞자리  26 -> 2
	B=Now%10;  // 현재값 N의 뒷자리  26 -> 6
	C=A+B; // 현재갚의 앞자리 + 뒷자리  2 + 6 = 8
	NEXT = 10*B + C%10; // 다음값 // 68 

	i+=1;
	
	
	while(NEXT!=Now){ // 다음값이 현재값 26과 같을떄까지 싸이클 돌아 
	A=NEXT/10;
	B=NEXT%10;
	C=A+B; 
	NEXT = 10*B + C%10; 
	i+=1;
	
	
	}
	
		
	printf("%d",i);
	
}
