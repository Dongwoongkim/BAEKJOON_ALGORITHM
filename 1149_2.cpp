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
int v[1001][4];
int d[1001][4];

int main()
{
    FASTio;

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++)
            cin >> v[i][j];
    }

    d[1][1] = v[1][1];
    d[1][2] = v[1][2];
    d[1][3] = v[1][3];

    for(int i=2;i<=n;i++)
    {
        d[i][1] = min(d[i-1][2], d[i-1][3]) + v[i][1];
        d[i][2] = min(d[i-1][1], d[i-1][3]) + v[i][2];
        d[i][3] = min(d[i-1][1], d[i-1][2]) + v[i][3];
    }


    cout << min(d[n][1],min(d[n][2],d[n][3]));



    return 0;
}