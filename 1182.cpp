#include <iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <vector>
using namespace std;
int n,k;
int m;

int rec(int p,int pos,vector <int> &num,vector<bool>& check,int a,vector <int> &ans)
{

	if(pos == a)
	{	int sum = 0;
	
		for(int i=0;i<a;i++)
		{
			sum += ans[i];
		}
				
		if(sum==k)
		{return 1;}
		
	return 0;
	}
	
	int cnt=0;
	
	for(int i=p;i<n;i++)
	{
		if(check[i]==false)
		{
			check[i]=true;
			ans[pos]=num[i];
			cnt += rec(i,pos+1,num,check,a,ans);
			check[i]=false;
		}
	}
	
return cnt;

}

int main()
{
	FASTio;
	cin >> n >> k;
	int answer=0;
	vector <int> num(n,0);
	vector <int> ans(n,0);
	vector <bool> check(n+1,false);	
	
	for(int i=0;i<n;i++)
		cin >> num[i];	
	
	for(int a=1;a<=n;a++)
	answer += rec(0,0,num,check,a,ans);
	
	cout << answer;



	return 0;
}