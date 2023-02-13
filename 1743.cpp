#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m,k;
int x,y;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int ans = -1;
int cnt;
vector<vector<int>> area(101,vector<int>(101,0));
vector<vector<bool>> check(101,vector<bool>(101));

int dfs(int y,int x)
{       
    int cnt = 1;
    check[y][x] = true;

    for(int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny>=0 && nx>=0 && nx<m && ny<n)
        {
            if(check[ny][nx]==false && area[ny][nx]==1)
            {   
                cnt += dfs(ny,nx);
            }
        }
    }

    return cnt;
}
int main()
{
    FASTio;
    cin >> n >> m >> k;

    for(int i=0;i<k;i++)
    {
        cin >> y >> x;
        area[y-1][x-1] = 1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   
            if(check[i][j]==false && area[i][j]==1)
            {
                ans = max(ans,dfs(i,j));
            }
        }
    }

    cout << ans << endl;
    return 0;
}