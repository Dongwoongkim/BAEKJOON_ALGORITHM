#include <iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <vector>
using namespace std;

int moum=0,zaum=0;

bool checkmoum(vector <char> &ans,int m){
	
	for(size_t i=0;i<m;i++){
		if(ans[i]=='a') return true;
		if(ans[i]=='e') return true;
		if(ans[i]=='i') return true;
		if(ans[i]=='o') return true;
		if(ans[i]=='u') return true;
	}
	
	return false;
}

bool checkzaum(vector <char> &ans,int m){
	
	for(size_t i=0;i<m;i++){
		if(ans[i]=='a') continue;
		if(ans[i]=='e') continue;
		if(ans[i]=='i')	continue;
		if(ans[i]=='o') continue;
		if(ans[i]=='u') continue;
		
		
		zaum++;
		
	}
	if(zaum>=2) return true;
	
	else
	{
		return false;
	}
	
}


void printanswer(int by,vector <char> &lock,vector <bool> &check,vector <char> &ans,int m,int n,int pos)
{	
	if(pos==m)
	{	
		int k;
		zaum=0;
		if(checkzaum(ans,m)==true && checkmoum(ans,m)==true)
		{	
			
			for(size_t i=0;i<m;i++)
				cout << ans[i];
			cout << endl;
			
		
		}
	
	}

	for(int i=by;i<n;i++)
	{	
		if(check[i]==false)
		{	
			ans[pos]=lock[i];
		
			check[i]=true;
			
			printanswer(i,lock,check,ans,m,n,pos+1);
			check[i]=false;
		}
	}

}

int main()
{
	FASTio;
	int m,n;

	cin >> m >> n;

	vector <char> lock(n);
	vector <bool> check(n+1,false);
	vector <char> ans(m);
	for(int i=0;i<n;i++)
		cin >> lock[i];

	sort(lock.begin(),lock.end());

	printanswer(0,lock,check,ans,m,n,0);

	return 0;
}