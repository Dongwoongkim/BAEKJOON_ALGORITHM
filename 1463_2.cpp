#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

/*
Top-Down
*/
int n;
int dp[1000001];
int ans(int n)
{
    if(n==1)
    {
        return 0;
    }

    if(dp[n] > 0) return dp[n];

    dp[n] = ans(n-1) + 1;

    if(n%2==0)
    {
        dp[n] = min(ans(n/2)+1, dp[n]); 
    }

    if(n%3==0)
    {
        dp[n] = min(ans(n/3)+1, dp[n]);
    }

    return dp[n];
}
int main()
{
    FASTio;
    cin >> n;
    ans(n);
    cout << dp[n];



    return 0;
}