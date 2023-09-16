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

vector<int> v(100001,0);
int d[3][100001];
int ans = -1001;
int main()
{
    FASTio;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }

    d[0][0] = v[0];

    for(int i=1;i<n;i++)
    {       
        d[0][i] = max(v[i]+d[0][i-1],v[i]);
    }

    d[1][0] = v[0];
    for(int i=1;i<n;i++)
    {
        d[1][i] = max(d[1][i-1] + v[i], d[0][i-1]); 
    }
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {   
            ans = max(ans,d[i][j]);
        }
        cout << endl;
    }

    cout << ans;
    



    return 0;
}