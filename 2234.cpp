#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;

// 서북동남
int dy[]={0,-1,0,1};
int dx[]={-1,0,1,0};
int rooms = 0;
int second = 0;
int third = 0;

bool check[51][51];
vector<vector<int>> area(51,vector<int>(51));
vector<vector<int>> areaNum(51,vector<int>(51));
int room[2501];

int bfs(int y,int x, int rooms)
{
    check[y][x] = true;
    areaNum[y][x]=rooms;
    queue <pair<int,int>> q;
    int k = 1;

    q.push(make_pair(y,x));

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny>=0 && nx>=0 && ny<n && nx<m)
            {
                if((area[y][x] & (1<<i))==0
                && check[ny][nx]==false)
                {   
                    q.push(make_pair(ny,nx));
                    check[ny][nx]=true;
                    areaNum[ny][nx]=rooms;
                    k++;
                }
            }
        }
    }

    second = max(second,k);
    return k;
}
int main()
{
    FASTio;
    cin >> m >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> area[i][j];
        }
    }
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(areaNum[i][j]==0)
            {
                rooms++;
                room[rooms] = bfs(i,j,rooms);
            }
        }
    }

    cout << rooms << endl;
    cout << second << endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   

            for(int k=0;k<4;k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];
                
                if(ny>=0 && nx>=0 && nx<m && ny<n)
                {   
                    if((area[i][j] & (1<<k))!=0)
                    {
                        if(areaNum[i][j]!=areaNum[ny][nx])
                        {   
                            if(third<room[areaNum[i][j]] + room[areaNum[ny][nx]])
                            {
                                third = room[areaNum[i][j]] + room[areaNum[ny][nx]];
                            }
                        }
                    }
                 
                }
            }
        }
    }
    
    cout << third;


    return 0;
}