#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;
int n,m,from,to;
vector<vector<int>>v(101,vector<int>());
vector<int>ans(51,0);
vector<int>arr(51,0);
bool check[51];
int M = 999999999;
int Mi;
int bfs(int start, int cnt)
{   
    check[start] = true;
    ans[start]=0;
    queue<int>q;
    q.push(start);

    int sum = 0;
    
    while(!q.empty())
    {   
        int from = q.front();
        q.pop();
        
        for(int i=0;i<v[from].size();i++)
        {   
            int depth  = ans[from]+1;
            int to = v[from].at(i);

            if(check[to]==false)
            {
                check[to]=true;
                q.push(to);
                ans[to] = depth;
                sum+=ans[to];
            }
        }        
    }
    return sum;
}
int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }



    for(int i=1;i<=n;i++)
    {
        arr[i] = bfs(i,0);
        // cout << arr[i] << ' ';
        fill(check,check+51,false);
        ans.clear();
    }

    for(int i=n;i>=1;i--)
    {
        if(M>=arr[i])
        {
            M = arr[i];
            Mi = i;
        }
    }

    cout << Mi;
     

    return 0;
}