#include <iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int t;
long long a,b;
long long k;
int main(){
cin >> t;
    
    for(int i=0;i<t;i++){
	
    cin >> a >> b;
    
    
       k = a;
       
       if(b==1){
       	if(a%10==0){
       		a= 10;
		   }
       	else{
       	a = a%10;
	   }}
      
	  	else{
        for(long long i=0;i<b-1;i++){
        if(a%10==0){
       		a= 10;
		   break;}
		   else{a = k*a%10;
		}}
}

        cout << a << endl;
        
        
}

}