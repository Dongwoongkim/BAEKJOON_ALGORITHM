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
int area[50][50];
int areaNum[50][50];
int room[2501];

int bfs(int y,int x, int rooms)
{
    queue <pair<int,int>> q;
    q.push(make_pair(y,x));
    areaNum[y][x]=rooms;
    int k = 0;

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        k++;
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny>=0 && nx>=0 && ny<n && nx<m)
            {
                if((area[y][x] & (1<<i))==0 && areaNum[ny][nx]==0)
                {   
                    q.push(make_pair(ny,nx));
                    areaNum[ny][nx]=rooms;
                }
            }
        }
    }

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

    for(int i=1;i<=rooms;i++)
    {
        second = max(second,room[i]);
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
                
                if(ny>=0 && nx>=0 && nx<m && nx<n)
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