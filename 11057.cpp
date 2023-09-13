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
int sum;
long long d[1001][11];

int main()
{
    FASTio;
    
    cin >> n;

    for(int i=0;i<=9;i++)
    {   
        d[1][i] = 1;
        d[2][i] = i+1;
    }

    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=j;k++)
            {
                d[i][j] += d[i-1][k]%10007 ;
            }
        }
    }

    for(int i=0;i<=9;i++)
    {
        sum += d[n][i]%10007;
    }

    cout << sum%10007;

    return 0;
}