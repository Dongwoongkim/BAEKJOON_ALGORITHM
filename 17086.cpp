#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;

vector<vector<int>>v(51,vector<int>(51));
vector<vector<int>>visited(51,vector<int>(51));
vector<vector<bool>>check(51,vector<bool>(51));

int dy[]={-1,1,0,0,-1,1,-1,1};
int dx[]={0,0,-1,1,-1,1,1,-1};
queue <pair<int,int>> q;
int ans = -1;

void bfs()
{  
    while(!q.empty())
    {   
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
    
        for(int i=0;i<8;i++)
        {   
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && nx>=0 && ny<n && nx<m)
            {
                if(v[ny][nx]==0 && check[ny][nx] == false)
                {  
                    q.push(make_pair(ny,nx));
                    check[ny][nx] = true;
                    visited[ny][nx] = visited[y][x]+1;
                }
            }
        }
    }

}

int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> v[i][j];
            if(v[i][j]==1)
            {
                q.push(make_pair(i,j));
            }
        }
    }
    bfs();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]!=0)
            {
                ans = max(visited[i][j],ans);
            }
        }
    }

    cout << ans;
}