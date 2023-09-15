#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int d[100001][3];

int n;

int main()
{
    FASTio;

    cin >> n;

    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;

    for(int i=2;i<=n;i++)
    {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2])%9901;
        d[i][1] = (d[i-1][0] + d[i-1][2])%9901;
        d[i][2] = (d[i-1][0] + d[i-1][1])%9901;
    }

    cout << (d[n][0] + d[n][1] + d[n][2])%9901;



    return 0;
}