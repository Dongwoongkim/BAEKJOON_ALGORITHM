#include <iostream>

using namespace std;

int n;
int mx=-1,mn=99999999;
int mx_index,mn_index;
int a[50];
int sum=0;
int b[50];
int main()
{
	cin >> n;
	
	// 제일 큰수 -> b배열의 제일작은수와 곱한다.
	// 두번째 큰수 - > b배열의 두번째작은수와 곱한다.
	// 세번째 큰수 - > b배열의 세번째 작은수와 곱한다.
	// ...
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}	  
	
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}	  
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(mx<=a[j])
			{
			mx = a[j];
			mx_index = j;
			}
		}
		
		int tmp;
		tmp = a[i];
		a[i]= mx;
		a[mx_index] = tmp;

		mx=-1;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(mn>=b[j])
			{
			mn = b[j];
			mn_index = j;
			}
		}
		
		int tmp;
	
		tmp = b[i];
		b[i]= mn;
		b[mn_index] = tmp;

		mn=99999999;
	}


	for(int i=0;i<n;i++)
	{
		sum += b[i]*a[i];
	}	  
	
	cout << sum;
	
	return 0;
}