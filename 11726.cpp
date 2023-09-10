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
long long d[1001];

long long dy(int n)
{
    for(int i=3;i<=n;i++)
    {
        d[i] = d[i-2]%10007 + d[i-1]%10007;
    }

    return d[n]%10007;
}
int main()
{
    FASTio;
    d[1]=1;
    d[2]=2;
    cin >> n;
    cout << dy(n);

    return 0;
}