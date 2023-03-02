#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
vector<vector<int>> area(501,vector<int>(501));
vector<vector<bool>> check(501,vector<bool>(501));

int ans=-1;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

// 꼭짓점 기준 

// ㅗ
int fks1(int y,int x)
{
    int sum=0;
    sum = area[y][x] + area[y][x+1] + area[y][x+2] + area[y-1][x+1];
    return sum;
}

// ㅜ
int fks2(int y,int x)
{
    int sum=0;
    sum = area[y][x] + area[y][x+1] + area[y][x+2] + area[y+1][x+1];
    return sum;
}

// ㅏ
int fks3(int y,int x)
{
    int sum=0;
    sum = area[y][x] + area[y+1][x] + area[y+2][x] + area[y+1][x+1];
    return sum;
}

// ㅓ
int fks4(int y,int x)
{
    int sum=0;
    sum = area[y][x] + area[y][x+1] + area[y-1][x+1] + area[y+1][x+1];
    return sum;
}

void dfs(int y,int x,int size,int sum)
{   
    if(size==4)
    {
        ans = max(sum,ans);
        return;
    }

    for(int i=0;i<4;i++)
    {   
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=0 && nx>=0 && nx<m && ny<n)
        {
            if(check[ny][nx]==false)
            {   
                check[ny][nx]=true;
                dfs(ny,nx,size+1,sum+area[ny][nx]);
                check[ny][nx]=false;
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
            cin >> area[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            check[i][j]=true;
            dfs(i,j,1,area[i][j]);
            check[i][j]=false;

            // ㅗ
            if(i-1>=0 && j+2<m) ans = max(ans,fks1(i,j));
            
            // ㅜ
            if(i+1<n && j+2<m) ans = max(ans,fks2(i,j));

            // ㅏ
            if(i+2<n && j+1<m) ans = max(ans,fks3(i,j));
            
            // ㅓ
            if(i+1<n && i-1>=0 && j+1<m)  ans = max(ans,fks4(i,j));
        }
    }

    cout << ans << endl;
    return 0;
}