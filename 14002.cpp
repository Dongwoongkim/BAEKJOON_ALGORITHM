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

vector<int> v(1001,0);
int d[1001];
int ans;

stack<int> st;
int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        d[i] = 1;
    }

    for(int i=0;i<n;i++)
    {  
        for(int j=i+1;j<n;j++)
        {
            if(v[j] > v[i])
            {   
                d[j] = max(d[i] + 1, d[j]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {   
        ans = max(ans, d[i]);
    }

    cout << ans << endl;

    int k = ans;
    for(int i=n-1;i>=0;i--)
    {
        if(d[i]==k)
        {
            st.push(v[i]);
            k--;
        }
    }
    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();

    }
    return 0;
}