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
stack<pair<int,int>> s;
int main()
{
    FASTio;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> num;
        
        while(!s.empty())
        {
            if(s.top().second > num)
            {
                cout << s.top().first << endl;
                s.push(make_pair(i,num));
                break;
            }
            else if(s.top().second < num)
            {
                s.pop();
            }
        }


        if(s.empty())
        {
            cout << 0 << endl;
        }
        s.push(make_pair(i,num));
        
    }


    return 0;
}