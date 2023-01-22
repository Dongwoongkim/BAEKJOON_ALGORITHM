#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int t;
int m,n,k;
int a,b;
int cnt = 0;
int arr[51][51];
bool check[51][51];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> q;

void bfs(int x, int y)
{   
    while(!q.empty())
    {   
        int y = q.front().first;
        int x = q.front().second;

        // cout << "y= " << y << ", x = " << x << endl;
        check[y][x] = true;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;

            if(check[ny][nx]==false && arr[ny][nx]==1)
            {   
                check[ny][nx]=true;
                q.push(make_pair(ny,nx));
            }
        }
    }
    // cout << endl;
    cnt++;
}
int main()
{
    FASTio;
    cin >> t;

    for(int i=0;i<t;i++)
    {
        cnt = 0;
        for(int i=0; i<51; i++)
        {   
        memset(check[i], false, sizeof(check[i]));
        }

        memset(arr,0,sizeof(arr));
        while(!q.empty()) q.pop();

        cin >> m >> n >> k;

        for(int j=0;j<k;j++)
        {
            cin >> a >> b; // a = 가로 x, b = 세로 y
            arr[b][a] = 1;  
        }

        // cout << endl;
        // for(int i=0;i<n;i++) // 세로 y
        // {
        //     for(int j=0;j<m;j++) // 가로 x
        //         cout << arr[i][j] << ' ';
        //         cout << endl;
        // }

        for(int i=0;i<n;i++) // 세로 y
        {
            for(int j=0;j<m;j++) // 가로 x
            {
                if(arr[i][j]==1 && check[i][j]==false)
                {  
                q.push(make_pair(i,j));
                bfs(j,i);
                }
            }
        }
        cout << cnt << endl;
    }


    return 0;
}