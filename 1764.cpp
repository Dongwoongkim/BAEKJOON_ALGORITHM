#include<iostream>
#include <vector>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int n,m;
int low,high,mid;
int cnt;
vector <string> d;// 듣도못함 
vector <string> b; // 보도못함 
vector <string> db; // 듣도보도못한 듣보잡  

int main(){
	FASTio;
		
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		char str[21];
		scanf("%s",str); 
		d.push_back(str);
	}
	
	for(int i=0;i<m;i++){
		char str[21];
		scanf("%s",str);
		b.push_back(str);
	}
	
	sort(d.begin(),d.end());
	
	
	for(int i=0;i<m;i++)
	{
		low = 0;
		high = n;
		while(low<=high)
		{
			
			mid = (low+high)/2;
			
			if(b[i]<d[mid]){
				high = mid -1;
			}
			if(b[i]>d[mid]){
				low = mid +1;
			}
			
			if(b[i]==d[mid]){
				db.push_back(b[i]);
				cnt++;
				break;
			}
			
		}
	
	}
	
	
	cout << cnt << endl;
	sort(db.begin(),db.end());
	for(int i=0;i<db.size();i++){
		cout << db[i] << endl;
	}



return 0;

}