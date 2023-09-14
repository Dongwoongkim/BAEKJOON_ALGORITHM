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

vector<int> v(100001);
vector<int> d(100001);

int ans = -1001;

int main()
{
    FASTio;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }

    d[0] = v[0];

    for(int i=1;i<n;i++)
    {   
        d[i] = max(v[i]+d[i-1],v[i]);
    }

    for(int i=0;i<n;i++)
    {
        ans = max(ans, d[i]);
    }

    cout << ans;

    

    return 0;
}