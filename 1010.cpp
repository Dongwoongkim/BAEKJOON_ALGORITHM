#include <iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main(){
	int test, a, b, p=1;
	int result;

	cin >> test;

	for(int i=0;i<test;i++){
		
		cin >> a >> b;
		
		for(int j=1;j<=a;j++){
			p=p*(b-j+1)/j;

		}
		
		result= p;
		cout << result << endl;
		p=1;
	}
return 0;}