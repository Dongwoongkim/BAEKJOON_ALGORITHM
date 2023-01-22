#include <stdio.h>

int main(){
	
	int n;
	double sum=0;
	
	double newscore[1000];
	double max=0;

	scanf("%d",&n);
	
	double score[1000];
	
	for(int i=0;i<n;i++){
		scanf("%lf",&score[i]);
	}

	for(int i=0;i<n;i++){
		if(max<score[i])
		max = score[i];
		}

	
	for(int i=0;i<n;i++){
		newscore[i] = score[i]/max*100; // 50 + 100 + 75
		sum += newscore[i];
}
	printf("%f",sum/n);	
	
	
}