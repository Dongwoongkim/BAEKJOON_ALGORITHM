#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;
string s;
stack<char> st;
int main()
{
    FASTio;
    cin >> n;
    // cin.ignore();
    for(int i=0;i<n;i++)
    {
        getline(cin, s);
        s += '\n';
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ' || s[i] == '\n'){
                while(!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            } else {
                st.push(s[i]);
            }
        }
    }

    return 0;
}