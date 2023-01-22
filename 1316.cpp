#include<iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int groupcheck(char word[101])
{
	
	if(!word[1]){
		return 1;
	}

	int i=0;
	int j;
	
	while(word[i+1])
	{
		if(word[i]==word[i+1])
		{
			i++;
		}
		
		else
		{
			j=i+2;
			while(word[j])
			{
				if(word[i]!=word[j]){
					j++;}
				else return 0;
				
			}
			i++;
		}
	
	
	}
	return 1;
}


int n;

char word[101];

int main(){
	FASTio;
	cin >> n;
		
	int sum=0;
	char word[101];
	for(int i=0;i<n;i++)
	{
		cin >> word;
		if(groupcheck(word)){
			sum++;
		}
		
	}
	
	cout <<  sum;}