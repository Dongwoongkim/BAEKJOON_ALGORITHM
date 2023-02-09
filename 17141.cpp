#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;
vector<vector<int>> area(51,vector<int>(51));
vector<pair<int,int>> virus;
int n, m;
int ans=-1;
int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};

int bfs(queue<pair<int,int>> &q,vector<vector<bool>> check, vector<vector<int>> visited)
{   
    int result=-1;

    while(!q.empty())
    {   
        for(int i=0;i<q.size();i++)
        {
            int y = q.front().first;
            int x = q.front().second;

            for(int i=0;i<4;i++)
            {
                int ny = y+dy[i];
                int nx = x+dx[i];

                if(ny>=0 && nx>=0 && ny<n && nx<n)
                {
                    if(check[ny][nx]==false && area[ny][nx]!=1)
                    {   
                        check[ny][nx]=true;
                        visited[ny][nx] = visited[y][x]+1;
                        q.push({ny,nx});
                    }
                }
            }
            q.pop();
        }    
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   
            if(area[i][j]==0 && check[i][j]==false)
                return -1;
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   
            result = max(result,visited[i][j]);
        }
    }
    return result;
}

int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)  
        {
            cin >> area[i][j];
            if(area[i][j]==2)
            {
                virus.push_back({i,j});
            }
        }
    }


    // 조합 
    vector<int> k(virus.size());
    for(int i=0;i<m;i++)
    {
        k[i] = 1;
    }
    for(int i=m;i<virus.size();i++)
    {
        k[i] = 0;
    }
    sort(k.begin(),k.end());
    
    do
    {   
        queue<pair<int,int>> q;
        vector<vector<int>> visited(51,vector<int>(51,0));
        vector<vector<bool>> check(51,vector<bool>(51,false));

        for(int i=0;i<virus.size();i++)
        {
            if(k[i]==1)
            {   
                int y,x;
                tie(y,x) = virus[i];
                q.push(make_pair(y,x));
                check[y][x]=true;
            }
        }

        int a = bfs(q,check,visited);
        if(a==-1) continue;
        else
        {
            if(ans==-1 || ans>a)
            {
                ans = a;
            }
        }

    } while (next_permutation(k.begin(),k.end()));

    cout << ans;

    return 0;
}