#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int ans[10002]={0};

int main()
{
	string s1,s2;
	string s3;
	
	
	cin >> s1;
	cin >> s2;
	
	for(int i=s1.length();i>=0;i--)
	{
		s1[i]=s1[i-1];
	}

	for(int i=s2.length();i>=0;i--)
	{
		s2[i]=s2[i-1];
	}
	
	s1[0]='0';
	s2[0]='0';
	
	int ls1,ls2;
	ls1= s1.length();
	ls2= s2.length();
	
	int mxls = max(ls1,ls2);
	
	if(ls1>=ls2)
	{	
		for(int i=mxls-1;i>=0;i--)
		{	
		s3[i] = s2[ls2-1];
		ls2--;
		if(ls2==0) break; 	 	
		}
		
		for(int i=0;s3[i]=='\0';i++)
		{
			s3[i]='0';
		}
		
	
		for(int i=mxls-1;i>=0;i--)
		{	
			if((s1[i]-'0')+(s3[i]-'0')>=10)
			{	
				
				ans[i]= (s1[i]-'0') +(s3[i]-'0')- 10;
			
				s1[i-1]= '0'+ int((s1[i-1]-'0') +1);
			}
			else
			{
		
			ans[i] = (s1[i]-'0') +(s3[i]-'0');
		
			}
		}

	}
	
	else
	{
		for(int i=mxls-1;i>=0;i--)
		{	
		s3[i] = s1[ls1-1];
		ls1--;
		if(ls1==0) break; 	 	
		}
		
		for(int i=0;s3[i]=='\0';i++)
		{
			s3[i]='0';
		}
		
		for(int i=mxls+2;i>=0;i--)
		{	
			if((s2[i]-'0')+(s3[i]-'0')>=10)
			{	
				
				ans[i]= (s2[i]-'0') +(s3[i]-'0')- 10;
			
				s2[i-1]= '0'+ int((s2[i-1]-'0') +1);
			}
			else
			{
		
			ans[i] = (s2[i]-'0') +(s3[i]-'0');
		
			}
		}
	}

	if(ans[0]!=0)
	{
		cout << ans[0];
		for(int i=1;i<mxls;i++)
		{
		cout << ans[i] ;
		}
		
	}
	else if(ans[0]==0)
	{
		for(int i=1;i<mxls;i++)
		{
		cout << ans[i] ;
		}
		
	}
	
	return 0;
}