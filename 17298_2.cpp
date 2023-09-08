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
vector<int> v(1000001);
vector<int> ans(1000001);

stack<int> st;

int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }

    st.push(v[n-1]);
    ans[n-1] = -1;

    
    for(int i=n-2;i>=0;i--)
    {        
        while(!st.empty() && st.top() <= v[i])
        {   
            st.pop();
        }

        if(st.empty())
        {
            st.push(v[i]);
            ans[i] = -1;
            continue;
        } else {
            ans[i] = st.top();
            st.push(v[i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << ans[i] << ' ';
    }


    return 0;
}