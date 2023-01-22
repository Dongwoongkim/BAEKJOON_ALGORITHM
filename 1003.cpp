#include <stdio.h>
int t;
int n;
int fibo[41];
int main(){
	scanf("%d",&t);
	
	for(int i=2;i<=40;i++){
		
		fibo[0]=0;
		fibo[1]=1;
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	
	for(int j=0;j<t;j++){
		
		scanf("%d",&n);
		
		if(n==0){
			printf("1 0\n");
			continue;
		}
		if(n==1){
			printf("0 1\n");
			continue;
		}
		else {
			printf("%d %d\n",fibo[n-1],fibo[n]);
			}
	}
}