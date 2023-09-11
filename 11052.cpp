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
vector<int> p(1001,0);
vector<int> d(1001,0);
int main()
{
    FASTio;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            d[i] = max(d[i-j] + p[j], d[i]);
        }
    }

    cout << d[n];


    return 0;
}