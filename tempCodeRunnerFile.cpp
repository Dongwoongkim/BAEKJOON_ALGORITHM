#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int hdy[] = {-1,-2,-2,-1,1,2,1,2};
int hdx[] = {-2,-1,1,2,-2,-1,2,1};

vector<vector<int>> v(201,vector<int>(201));
vector<vector<int>> visited(201,vector<int>(201));

bool check[201][201];
int k,w,h;
int cnt = 0;

void bfs(int y,int x)
{
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(y,x),0));

    while(!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int hm = q.front().second;

        check[y][x]=true;
        q.pop();

        if(y==h-1 && x==w-1)
        {   
            break;
        }

        if(hm<k)
        {
            for(int i=0;i<8;i++)
            {
                int ny = y + hdy[i];
                int nx = x + hdx[i];

                if(ny>=0 && nx>=0 && nx<w && ny<h)
                {
                    if(check[ny][nx]==false && v[ny][nx]==0)
                    {
                        q.push(make_pair(make_pair(ny,nx),hm+1));

                        if(visited[ny][nx]==0 || visited[ny][nx] > visited[y][x]+1)
                            visited[ny][nx] = visited[y][x]+1;
                    }
                }
            }
        }

        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny>=0 && nx>=0 && nx<w && ny<h)
            {
                if(check[ny][nx]==false && v[ny][nx]==0)
                {
                    q.push(make_pair(make_pair(ny,nx),hm));

                    if(visited[ny][nx]==0 || visited[ny][nx] > visited[y][x]+1)
                        visited[ny][nx] = visited[y][x]+1;
                }
            }
        }
    
    }
}

int main()
{
    FASTio;
    cin >> k >> w >> h;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> v[i][j];
        }
    }

    if( w==1 && h==1 && v[0][0]==0)
    {
        cout << 0;
        return 0;
    }

    bfs(0,0);
    cout << endl;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }

    if(visited[h-1][w-1]==0)
    {
        cout << -1;
    }
    else
    {
        cout <<visited[h-1][w-1];
    }

    return 0;
}