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
int d[91][3];
int ans[91];
int main()
{
    FASTio;
    cin >> n;
  
    d[1][1]=1;
    d[2][0]=1;
    d[3][0]=2;

    for(int i=4;i<=n;i++)
    {   
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0];
    }

    cout << d[n][0] << endl;

    return 0;
}