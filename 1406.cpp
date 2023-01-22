#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

int main()
{   
    int n;
    string s;
    char cmd;
    cin >> s;
    cin >> n;
    
    int cursor = s.length();

    stack <char> left,right;

    for(int i=0;i<s.length();i++)
    {
        left.push(s[i]);
    }

    while(n--)
    {   
        cin >> cmd;

        if(cmd=='P')
        {   
            char tmp;
            cin >> tmp;
            left.push(tmp);
        }

        else if(cmd=='L')
        {   
            if(!left.empty())
            {
                right.push(left.top());
                left.pop();
            }   
            
        }

        else if(cmd=='B')
        {
            if(!left.empty())
            {
                left.pop();
            }
        }

        else if(cmd=='D')
        {
            if(!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
    }

    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
   
    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}