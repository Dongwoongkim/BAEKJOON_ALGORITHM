#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;


// d[k][n] = k개의 정수를 사용해서 n을 만드는 경우의 수 
long long d[201][201];

int n, k;
int main()
{
    FASTio;
    cin >> n >> k;

    for(int i=0;i<=n;i++)
    {
        d[1][i] = 1;
    }

    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int l=0;l<=j;l++)
            {
                d[i][j] += d[i-1][j-l];
                d[i][j]%=1000000000;
            }
        }
    }

    cout << d[k][n]%1000000000;
    return 0;
}