#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int area[101][101][101];
int visited[101][101][101];
int dy[]={-1,1,0,0,0,0};
int dx[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,-1,1};
queue<pair<int,pair<int,int>>> q;
bool check[101][101][101];
int n,m,h;
int ans;
void bfs()
{   
    while(!q.empty())
    {
        for(int i=0;i<q.size();i++)
        {
            int z = q.front().first;
            int y = q.front().second.first;
            int x = q.front().second.second;   
            
            check[z][y][x]=true;

            for(int i=0;i<6;i++)
            {   
                // 상하좌우 위아래
                int nz = z + dz[i];
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(nz>=0 && ny>=0 && nx>=0
                && nz<h && ny<n && nx<m)
                {
                    if(check[nz][ny][nx]==false
                    && area[nz][ny][nx]==0)
                    {
                        check[nz][ny][nx]=true;
                        q.push(make_pair(nz,make_pair(ny,nx)));
                        visited[nz][ny][nx] = visited[z][y][x]+1;
                    }
                }   

            
            }
            q.pop();
        }
    }
}
int main()
{
    FASTio;
    cin >> m >> n >> h;

    for(int k=0;k<h;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> area[k][i][j];

                if(area[k][i][j]==1)
                {
                    q.push(make_pair(k,make_pair(i,j)));
                }
            }
        }
    }

    bfs();

    for(int k=0;k<h;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cout << visited[k][i][j] << ' ';
                if(area[k][i][j]==0 && check[k][i][j]==false)
                {
                    cout << -1;
                    return 0;
                }

                else
                {
                    ans = max(visited[k][i][j],ans);
                }
            }
        }

    }
    cout << ans << endl;
    return 0;
}