#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;
int num;
vector<int> arr(1000001,0);
vector<int> ans(1000001,-1);
stack <int> st;


int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    st.push(arr[n-1]);

    for(int i=n-2;i>=0;i--)
    {                   
        while(!st.empty() && st.top() <= arr[i])
        {   
            st.pop();
        }

        if(!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }

    
    return 0;
}