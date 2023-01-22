#include <stdio.h>
int fact=1;
int count=0;
int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		
		if(i%5==0){
			count++;
		}
		
		if(i%25==0){
			count++;
		}
		
		if(i%125==0){
			count++;
		}
		if(i%625==0){
			count++;
		}

	}
	
	
	
if(n==0){
	printf("0");
}
else{	printf("%d",count);
}}