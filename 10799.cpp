#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

string s;

int sum = 0;

int main()
{
    FASTio;
    cin >> s;
    stack <char> st;

    for(int i=0;i<s.length();i++)
    {   
        // 여는 괄호
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        // 닫는 괄호 
        else
        {   
            st.pop();
            if(s[i]==')' && s[i-1] == ')')
            {   
                
                sum +=1;
            }
            else
            {   
                sum += st.size();
            }

            cout << sum << endl;
        }
    }
    cout << sum;
    return 0;
}