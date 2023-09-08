#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int main()
{
    FASTio;
    string s;
    stack<char> st;
    bool tag = false;
    getline(cin, s);

    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '<')
        {   
            while(!st.empty())
            {
                cout << st.top();
                st.pop();
            }

            cout << s[i];
            tag = true;
        }
        else if(s[i] == '>')
        {
            cout << s[i];
            tag = false;
        }
        else if(tag) 
        {
            cout << s[i];
        } else 
        { 
            if(s[i] == ' ')
            {   
                while(!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << s[i];
            } else
            {
                st.push(s[i]);
            }
        }
       
    }

    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}