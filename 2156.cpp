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
int d[10001];
int v[10001];
int main()
{
    FASTio;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];  

    d[1] = v[1];
    d[2] = d[1] + v[2];


    for(int i=3;i<=n;i++)
    {
        d[i] = max(d[i-1], max(d[i-2]+v[i], d[i-3]+v[i-1]+v[i]));
    }

    cout << d[n];

    return 0;

}