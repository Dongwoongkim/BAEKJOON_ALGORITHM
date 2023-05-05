#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;
int ans = 0;

vector<int> v(1001);
vector<int> dp(1001);
int main()
{
    FASTio;
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        dp[i]=1;
    }
    

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
           
        }
    }

    for(int i=0;i<n;i++)
    {
        ans = max(dp[i],ans);
    }
    cout << ans;

    return 0;   
}