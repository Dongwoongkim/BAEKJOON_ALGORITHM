#include <iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

long long max(long long array[10001],int k,int n){
	long long count = 0;
	long long mid,high,low;

	
	
	long long max = array[0];
	for(int i=1;i<k;i++){
		if(max<=array[i]){
			max = array[i];
		}
	}
	// 배열의 최대값 구하기  
		low = 1;
		high = max;
	
	while(low<=high){
		
	    
		mid = (low + high) / 2;
		count =0;
		
		for(int i=0;i<k;i++){
			count += array[i] / mid;
		}
		
		
		if(count<n){
			high = mid -1;
		}
		if(count>=n){
			low = mid + 1;
			
		}
		if(low>high){
			break;
		}
		
	}
	
return high;

}

int k,n;
long long arr[10001];
int main(){	
	FASTio;
	
	cin >> k >> n;
	
	for(int i=0;i<k;i++){
		
		cin >> arr[i];
	}
	if(k==1 && n!=0){
		printf("%lld",arr[0]/n);
		return 0;
	}
	
	cout << max(arr,k,n);


	
return 0; 
	
}