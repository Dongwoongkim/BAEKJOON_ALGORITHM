#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <unordered_map>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;
vector<int> v(1000001);
vector<int> cnt(1000001);
vector<int> ans(1000001,-1);
unordered_map<int, int> m;

stack<pair<int,int>> st;

int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        cnt[i] = m[v[i]];
    }

    st.push(make_pair(v[n-1], cnt[n-1]));

    for(int i=n-2;i>=0;i--)
    {        
        while(!st.empty() && st.top().second <= cnt[i])
        {
            st.pop();
        }
    
        if(st.empty())
        {
            st.push(make_pair(v[i], cnt[i]));
            continue;
        } else {
            ans[i] = st.top().first;
            st.push(make_pair(v[i], cnt[i]));
        }
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }


    return 0;
}