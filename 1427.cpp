#include <iostream>
#include <string.h>
#include <vector>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int n;

vector <int> s;

int main(){
	
	cin >> n;
		

	while(n!=0){
		
		s.push_back(n%10);
		n /=10;
		
	}
	
	sort(s.begin(),s.end());
	
	for(int i=s.size()-1;i>=0;i--){
		cout << s[i] ;
	}
	
	
	
	return 0;
	}