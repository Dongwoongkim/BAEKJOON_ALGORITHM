#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
int ans;
vector<vector<int>> area(51,vector<int>(51));
int dy[] = {-1,1,0,0,-1,1,1,-1};
int dx[] = {0,0,-1,1,-1,1,-1,1};

void bfs(int y, int x,vector<vector<bool>>& check)
{
    queue<pair<int,int>> q;

    q.push(make_pair(y,x));

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
                if(check[ny][nx]==false && 
                area[ny][nx]==1)
                {
                    q.push(make_pair(ny,nx));
                    check[ny][nx]=true;
                }
            }
        }
    }
}
int main()
{
    FASTio;
    while(1)
    {
        vector<vector<bool>> check(51,vector<bool>(51,false));

        cin >> m >> n;
        if(!n && !m) break;

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
                if(area[i][j]==1 &&
                check[i][j]==false)
                {
                    bfs(i,j,check);
                    ans++;
                }
            }
        }

        cout << ans << endl;
        ans = 0;
    }

    return 0;
}