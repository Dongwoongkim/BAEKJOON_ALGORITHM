#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
vector<string> s(101);
bool check[101][101];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

long ansW = 0;
long ansB = 0;
int W,B;

void dfs(int y,int x)
{       
    if(s[y][x]=='W') W++;
    if(s[y][x]=='B') B++;
    
    check[y][x]=true;

    for(int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny>=0 && nx>=0 && nx<m && ny<n)
        {
            if(s[y][x]=='W' && check[ny][nx]==false && s[ny][nx]=='W')
            {   
                dfs(ny,nx);
            }

            if(s[y][x]=='B' && check[ny][nx]==false && s[ny][nx]=='B')
            {   
                dfs(ny,nx);
            }
        }
    }

}
int main()
{
    FASTio;

    cin >> m >> n;

    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   
            if(check[i][j]==false && s[i][j]=='W')
            {
                W = 0;
                dfs(i,j);
                ansW += W*W;
            }
            else if(check[i][j]==false && s[i][j]=='B')
            {
                B = 0;
                dfs(i,j);
                ansB += B*B;
            }
        }
    }

   
    cout << ansW << ' ' << ansB;
    return 0;
}