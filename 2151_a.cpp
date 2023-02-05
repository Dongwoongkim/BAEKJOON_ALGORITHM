#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int n;
vector<vector<char>> area(51,vector<char>(51));
vector<pair<int,int>> mirror;
vector<vector<int>> mirrorNum(51,vector<int>(51));
vector<vector<int>> doorNum(51,vector<int>(51));
vector<pair<int,int>> door;
int start=-1;
int dest=-1;

void bfs(int start,vector<int>&dist, vector<vector<bool>>&check)
{
    queue<int>q;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0;i<mirror.size();i++)
        {
            if(check[now][i] && dist[i]==-1)
            {   
                cout << i << ' ' << dist[i] << endl;
                dist[i] = dist[now]+1;
                q.push(i);
            }
        }
    }
}

int main()
{
    FASTio;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> area[i][j];

            if(area[i][j]=='#')
            {
                if(start==-1)
                {
                    start = mirror.size();
                }
                else
                {
                    dest = mirror.size();
                }
                mirror.push_back({i,j});
                mirrorNum[i][j] = mirror.size()-1;
            }

            else if(area[i][j]=='!')
            {
                mirror.push_back({i,j});
                mirrorNum[i][j] = mirror.size()-1;
            }
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout << mirrorNum[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    vector<vector<bool>>check(mirror.size(),vector<bool>(mirror.size(),false));
    
    for(int i=0;i<mirror.size();i++)
    {
        for(int k=0;k<4;k++)
        {
            int ny = mirror[i].first + dy[k];
            int nx = mirror[i].second + dx[k];
            
            while(1)
            {
                if(!(ny>=0 && nx>=0 && nx<n && ny<n))
                {  
                    break;
                }

                if(area[ny][nx]=='*')
                {
                    break;
                }

                if(area[ny][nx]=='#' || area[ny][nx]=='!')
                {
                    check[i][mirrorNum[ny][nx]] = true;
                    // cout << i << ' ' << mirrorNum[ny][nx] << endl;
                }

                ny += dy[k];
                nx += dx[k];
            }
        }
    }
    
    vector<int> dist(mirror.size(),-1);


    bfs(start,dist,check);
    
    cout << dist[dest];


  
    return 0;
}