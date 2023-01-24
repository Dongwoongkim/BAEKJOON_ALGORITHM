#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

int n,m;
string s;
int cnt=0;
int a,b;
int arr[201][201];
int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i=1;i<=n-2;i++)
    {   
        for(int j=i+1;j<=n-1;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(arr[i][j] == 1 || arr[i][k]==1 || arr[j][k]==1) continue;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}