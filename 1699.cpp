#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int d[100001];
int n;

int main()
{
    FASTio;
    d[1]=1;
    d[2]=2;
    d[3]=3;

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        d[i] = i;
    }
    
    for(int i=4;i<=n;i++)
    {
        for(int j=1;j*j<=i;j++)
        {      
            if(i-(j*j)>=0)
            {   
                d[i] = min(d[i], d[i-(j*j)]+1);
            }
        }
    }

    cout << d[n] << endl;



    return 0;
}