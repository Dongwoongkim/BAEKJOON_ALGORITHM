#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;

int ans;
int d[501][501];
int v[501][501];

int main()
{
    FASTio;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin >> v[i][j];
        }
    }


    d[0][0] = v[0][0];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i+1;j++)
        {
            d[i+1][j] = max(d[i+1][j], d[i][j] + v[i+1][j]); // 바로 아래 
            d[i+1][j+1] = max(d[i+1][j+1], d[i][j] + v[i+1][j+1]); // 오른쪽 아래 
        }
    }

    for(int i=0;i<n;i++)
    {
        ans = max(ans, d[n-1][i]);
    }

    cout << ans;



    return 0;
}