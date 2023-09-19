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

vector<int> v;
vector<bool> check(9,false);
vector<int> ans(9,0);

void rec(int pos)
{
    if(pos==m)
    {
        for(int i=0;i<m;i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    else
    {
        int pre = -1;
        for(int i=0;i<n;i++)
        {
            if(check[i]==false && pre != v[i])
            {   
                ans[pos] = v[i];
                pre = ans[pos];
                check[i] = true;
                rec(pos+1);
                check[i] = false;
            }

        }
    }
}
int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());
    rec(0);

    return 0;
}