#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
vector<int> arr;
vector<bool> check(8,false);
vector<int> ans;
void rec(int start, int pos)
{   
    if(pos==m)
    {   
        for(int i=0;i<m;i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }

    else
    {
        for(int i=start;i<n;i++)
        {   
            ans.push_back(arr[i]);
            rec(i,pos+1);
            ans.pop_back();  
        }
    }
}
int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int num; cin>>num;
        arr.push_back(num);
    }

    sort(arr.begin(),arr.end());
    rec(0,0);

    return 0;
}