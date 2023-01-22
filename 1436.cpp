#include <iostream>
#include <algorithm>
using namespace std;

int pipe[1001];

int main()
{
	int n,l;
	int cnt =0;
	cin >> n >> l;
	
	for(int i=0;i<n;i++)
	{
		cin >> pipe[i];
	}
	
	sort(pipe,pipe+n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(pipe[j]-pipe[i]+1<=l)
			{
				continue;
			}
			
			else
			{
				i = j-1;
				cnt++;
				break;
			}
		}
		
		if(i==n-1)
		{
			cnt++;
		}
	}
	
	
	cout << cnt;
	return 0;
}