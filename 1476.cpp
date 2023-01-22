#include <iostream>
using namespace std;

int main()
{
	int E,S,M;
	cin >> E >> S >> M;
	
	int a=1,b=1,c=1;
	int cnt=1;
	
	while(1)
	{
		if(a==E && b==S && c==M) break;
		else
		{		
			cnt++;
			a++;
			b++;
			c++;
		}
			
		if(a==16) a=1;
		
		if(b==29) b=1;
		
		if(c==20) c=1;
	}
	
	cout << cnt << endl;
}