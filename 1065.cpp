#include <iostream>

using namespace std;

int n;

int cnt=0;


int main()
{	
	cin >> n;
	
	if(n<100)
	{
		cout << n;
	}
	
	else
	{
		for(int i=100;i<=n;i++)
		{
			
			if( ((i/10)%10)*2 == 
				((i/100) + (i%10)))
				cnt++;
				
			else 
			{
				continue;
			}
		}
		
		cout << 99+cnt;

	}
	
	return 0;
	
	
}