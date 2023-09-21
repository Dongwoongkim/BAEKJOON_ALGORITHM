#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;

void rec(int pos, vector<int> &v, vector<int> &ans, vector<bool> &check)
{
    if(pos==7)
    {
        for(int i=1;i<=6;i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    else
    {   
        for(int i=pos;i<=n;i++)
        {   
            if(check[i]==false && ans[pos-1] < v[i])
            {
                check[i]=true;
                ans[pos] = v[i];
                rec(pos+1, v, ans , check);
                check[i]=false;
            }
        }
    }
}

int main()
{
    FASTio;

    while(1)
    {
        cin >> n;
        if(n==0) break;
        vector<int> v(n+1,0);
        vector<int> ans(n+1,0);
        vector<bool> check(n,false);
        
        for(int i=1;i<=n;i++)
        {
            cin >> v[i];            
        }

        rec(1,v,ans,check);
        cout << endl;
    }


    return 0;
}