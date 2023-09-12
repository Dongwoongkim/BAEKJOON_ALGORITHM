#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int t,n;
long long d[100001][4];

int main()
{
    FASTio;
    d[1][1]=1;
    d[2][2]=1;
    d[3][1]=1;
    d[3][2]=1;
    d[3][3]=1;

    cin >> t;

    for(int i=4;i<=100000;i++)
    {
        for(int j=1;j<=3;j++)
        {   
            for(int k=1;k<=3;k++)
            {   
                if(j!=k)
                {
                    d[i][j] += (d[i-j][k] % 1000000009);

                }
            }
        }
    }    
    while(t--)
    {
        cin >> n;
        cout << (d[n][1]+ d[n][2] + d[n][3])%1000000009 << endl;
    }

    return 0;
}