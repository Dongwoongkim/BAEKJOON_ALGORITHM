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
int v[1001];
int increase[1001];
int decrease[1001];
int ans = -999999;

int main()
{
    FASTio;
    cin >> n;

    for(int i=1;i<=n;i++) cin >> v[i];
    
    for(int i=1;i<=n;i++)
    {
        increase[i] = 1;
        decrease[i] = 1;
    }

    for(int i=1;i<=n;i++)
    {   
        for(int j=i+1;j<=n;j++)
        {
            if(v[j] > v[i])
            {
                increase[j] = max(increase[i]+1, increase[j]);
            }
        }
    }

    for(int i=n;i>=1;i--)
    {   
        for(int j=i-1;j>=1;j--)
        {
            if(v[j] > v[i])
            {
                decrease[j] = max(decrease[i]+1, decrease[j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        ans = max(decrease[i]-1 + increase[i]-1, ans);
    }

    cout << ans + 1;


    return 0;
}