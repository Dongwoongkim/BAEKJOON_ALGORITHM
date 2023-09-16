#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int d[31];
int n;

int main()
{
    FASTio;
    cin >> n;

    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    
    for(int i=3;i<=n;i++)
    {
        if(i%2==0)
        {
            for(int j=2;j<=n;j+=2)
            {   
                if(j==2)
                {
                    d[i] = d[i-j] * d[2];
                }
                else if(i-j>=0) d[i] += d[i-j] * 2;
            }
        }
    }
    cout << d[n];

    return 0;
}