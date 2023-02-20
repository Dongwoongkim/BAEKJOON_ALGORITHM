#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n;
string st;

map <string,int> m;

int main()
{
    FASTio;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> st;
        m[st]++;
    
    }
    int cnt = 0;

    for(auto & a : m)
    {   
        cnt = max(a.second,cnt);
    }

    for(auto & a : m)
    {
        if(a.second == cnt)
        {
            cout << a.first;
            break;
        }
    }




    return 0;
}