#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n;
int RGB[3000][3];
int dp[3000][3];

int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> RGB[i][j];
        }
    }
    for(int i=0;i<3;i++)
        dp[0][i] = RGB[0][i];

    // 다음칸 (1번부터) : 현재집의 비용(RGB로 각각 칠했을 때) + 이전까지 최소 비용 (현재칠한 색과 달라야함)
    for(int i=1;i<n;i++)
    {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + RGB[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + RGB[i][1];
        dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + RGB[i][2];
    }

    cout << min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    
    


    return 0;
}