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
int ans = 1000000*5;
vector<vector<int>> v(11,vector<int>(11,0));

vector<int> way(11,0);
vector<bool> check(11,false);

void rec(int pos)
{
    if(pos == n)
    {
        int sum = 0;
        for(int i=0;i<n-1;i++)
        {   
            if(v[way[i]][way[i+1]]==0)
            {
                return;
            }
            sum += v[way[i]][way[i+1]];
        }

        if(v[way[n-1]][way[0]] == 0) 
        {
            return;
        } else
        {
            sum += v[way[n-1]][way[0]];
        }
        ans = min(sum,ans);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(check[i]==false)
            {   
                way[pos] = i;
                check[i]=true;
                rec(pos+1);
                check[i]=false;
            }
        }
    }
}
int main()
{
    FASTio;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> v[i][j];
        }
    }

    rec(0);
    cout << ans;


    return 0;
}