#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int length;
long long sum;
long long d[101][10];

int main()
{
    FASTio;
    cin >> length;

    for(int i=1;i<=9;i++)
    {
        d[1][i] = 1;
    }

    for(int n=2;n<=100;n++)
    {
        for(int l=0;l<=9;l++)
        {   
            if(l-1>=0)
            {
                d[n][l] += d[n-1][l-1]%1000000000;
            }
            if(l+1<=9)
            {
                d[n][l] += d[n-1][l+1]%1000000000;
            }
        }
    }

    for(int i=0;i<=9;i++)
    {   
        sum += d[length][i]%1000000000;
    }

    cout << sum%1000000000;


    return 0;
}