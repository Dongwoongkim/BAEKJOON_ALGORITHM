#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
vector<vector<char>> area(11,vector<char>(11));
int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> area[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            cout << area[i][j];
        }
        cout << endl;
    }

    return 0;
}