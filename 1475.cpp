#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int array[10]={0,0,0,0,0,0,0,0,0,0};
	vector <int> num;
	
	int n;
	int cnt=1;
	
	cin >> n;
	
	int k;
	
	if(n==0)
	{
		cout << 1;
		return 0;
	}
	
	while(1)
	{
		k = n%10;
		n/=10;
		
		
		if(k==6 || k==9) array[6]++;
		
		else	
			array[k]++;
		
		if(n==0)
		{
			break;
		}
		cnt++;
	}
	int mx=0;
	if(array[6]%2==1) array[6]++;
	
	array[6]/=2;
	
	
	for(int i=0;i<=9;i++)
		if(mx<array[i]) mx= array[i];
	
	
	cout <<mx;
	
	
}