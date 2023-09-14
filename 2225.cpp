#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,k;


// d[n][k] = k개를써서 n을 만드는 경우 
long long d[201][201];

int main()
{
    FASTio;
    cin >> n >> k;
    
    for(int i=1;i<=n;i++)
    {
        d[i][1] = 1;
    }
    
    for(int i=1;i<=k;i++)
    {
        d[1][i] = i;
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            d[i][j] = d[i-1][j]%1000000000 + d[i][j-1]%1000000000;
        }
    }

    cout << d[n][k]%1000000000;
    
}