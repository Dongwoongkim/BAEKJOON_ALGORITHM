#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,m;

vector<int> k(9,0);
vector<bool> check(9,false);
vector<int> v(9,0);

void rec(int pos)
{   
    if(pos == m)
    {
        for(int i=0;i<m;i++)
        {
            cout << k[i] << ' ';
        }
        cout << endl;
    } 

    else
    {
        for(int i=1;i<=n;i++)
        {   
            if(k[pos-1] <= i)
            {
                k[pos] = i;
                rec(pos+1);
            }
        }
    }
}

int main()
{
    FASTio;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i];

    rec(0);
    return 0;
}