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
int d[1001];

int main()
{
    FASTio;
    d[1]=1;
    d[2]=3;
    cin >> n;

    for(int i=3;i<=n;i++)
    {
        d[i] = (d[i-2]*2 + d[i-1])%10007;
    }

    cout << d[n];

    return 0;
}