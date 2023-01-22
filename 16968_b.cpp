#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int ans = 1;
string s;
int main()
{
    FASTio;
    cin >> s;

    for(int i=0;i<s.length();i++)
    {
        int cnt = (s[i]=='c' ? 26 : 10);

        if(i>0 && s[i]==s[i-1])
        {
            cnt-=1;
        }

        ans *= cnt;
    }

    cout << ans << endl;
    return 0;
}