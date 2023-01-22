#include <iostream>

using namespace std;

long long ans(int a,int pow,int c)
{	
	if(pow==1) return a%c;
	
	else
	{
		if(pow%2==1)
		{
			return (a%c * ans(a,pow-1,c)%c )%c;
		}
		
		else if(pow%2==0)
		{
			long long half = ans(a,pow/2,c)%c;
			return (half*half)%c;
		}
	}
}
int main()
{
	
	long long a,b,c;
	cin >> a >> b >> c;
	
	cout << ans(a,b,c)%c;
	
}