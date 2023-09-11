#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int t;
int n;
long long d[1000001];

int main()
{
    FASTio;
    cin >> t;

    d[1]= 1;
    d[2]= 2;
    d[3]= 4;
    for(int i=4;i<=1000000;i++)
    {
        d[i] = (d[i-1]+d[i-2]+d[i-3])%1000000009;
    }
    
    while(t--)
    {   
        cin >> n;
        cout << d[n] << endl;
    }


    return 0;
}