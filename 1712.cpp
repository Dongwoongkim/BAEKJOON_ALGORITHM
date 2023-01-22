#include<iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <algorithm> 

using namespace std;
unsigned int a,b,c;
int i;
int main(){
	
	cin >> a >> b >> c;
	if(b>=c){
		printf("-1");
	}
	else{
	printf("%d",a/(c-b)+1);
	
}

return 0;}
		
		
	
	
		