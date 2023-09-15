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

int main()
{
    FASTio;
    cin >> t;

    while(t--)
    {
        cin >> n;
        vector<vector<int>> v(2, vector<int>(n,0));
        vector<vector<int>> d(2, vector<int>(n,0));

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> v[i][j];
            }
        }
        d[0][0] = v[0][0];
        d[1][0] = v[1][0];
        d[0][1] = v[1][0] + v[0][1];
        d[1][1] = v[0][0] + v[1][1];

        for(int i=2;i<n;i++)
        {
            d[0][i] = max(d[1][i-1],d[1][i-2]) + v[0][i];
            d[1][i] = max(d[0][i-1],d[0][i-2]) + v[1][i];
        }

        cout << max(d[0][n-1], d[1][n-1]) << endl;

    }

    return 0;
}