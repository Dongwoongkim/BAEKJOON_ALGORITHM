#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n;
vector<int> v(301);
vector<int> dp(301);

int main()
{
    FASTio;
    cin >> n;
    for(int i=0;i<n;i++)
    {   
        cin >> v[i];
    }

    dp[0] = v[0];
    dp[1] = v[0]+v[1];
    dp[2] = max(v[0]+v[2],v[1]+v[2]);

    for(int i=3;i<n;i++)
    {
        dp[i] = max(dp[i-2]+v[i], dp[i-3]+v[i-1]+v[i]);
    }
    cout << dp[n-1];


    return 0;
}