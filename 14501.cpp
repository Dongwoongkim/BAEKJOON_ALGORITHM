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
vector<int> t(16,0);
vector<int> p(16,0);
vector<int> d(16,0);
int ans = -1;

int main()
{
    FASTio;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> t[i] >> p[i];
    }


    for(int i=n;i>0;i--)
    {
        if(t[i] + i > (n+1))
        {
            d[i] = d[i+1];
        }
        else
        {
            d[i] = max(p[i] + d[i + t[i]], d[i+1]);
        }
    }

    cout << d[1];
    
    return 0;
}