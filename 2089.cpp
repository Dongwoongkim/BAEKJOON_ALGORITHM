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

stack<int> s;

int main()
{
    FASTio;
    cin >> n;

    if(n==0)
    {
        cout << 0;
        return 0;
    }
    while(1)
    {
        if(n==0) break;
        
        if(n<0 && n*(-1)%2==1)
        {
            n-=1;
            s.push(1);
            n = n/(-2);
        } else
        {
            s.push(n%(-2));
            n = n/(-2);
        }
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}