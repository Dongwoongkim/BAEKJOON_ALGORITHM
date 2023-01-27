#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n;
vector<vector<int>> area(32,vector<int>(32));

int rec(int y,int x,int dir)
{   

    // 목적지 도달시
    if(y==n-1 && x==n-1)
    {
        return 1;
    }
    int ans = 0;


    //가로인경우
    if(dir==0)
    {
        // case 1
        if(x+1<n && area[y][x+1]!=1)
        {
            ans += rec(y,x+1,0);
        }

        // case 2

        if(x+1<n && y+1<n &&
        area[y][x+1]!=1 && area[y+1][x+1]!=1 && area[y+1][x]!=1)
        {
            ans += rec(y+1,x+1,2);
        }

    }
    //세로
    else if(dir==1)
    {
        // case 1
        if(y+1<n && area[y+1][x]!=1)
        {
            ans += rec(y+1,x,1);
        }

        // case 2
        if(x+1<n && y+1<n &&
        area[y][x+1]!=1 && area[y+1][x+1]!=1 && area[y+1][x]!=1)
        {
            ans += rec(y+1,x+1,2);
        }

    }
    //대각선
    else if(dir==2)
    {
        // case 1
        if(x+1<n && area[y][x+1]!=1)
        {
            ans += rec(y,x+1,0);
        }

        // case 2
        if(y+1<n && area[y+1][x]!=1)
        {
            ans += rec(y+1,x,1);
        }

        // case 3
        if(x+1<n && y+1<n &&
        area[y][x+1]!=1 && area[y+1][x+1]!=1 && area[y+1][x]!=1)
        {
            ans += rec(y+1,x+1,2);
        }
        
    }

    return ans;
    
}

int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cin >> area[i][j];
        }
    }

    int ans = rec(0,1,0);

    cout << ans;
    


    return 0;
}