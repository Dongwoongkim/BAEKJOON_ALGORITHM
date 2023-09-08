#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

string s;
string s0;
int sum;
int main()
{
    FASTio;

    cin >> s;

    if(s.length() % 3 == 1)
    {
        s0 += "00";
    } else if(s.length() % 3 == 2)
    {
        s0 += "0";
    }

    s = s0 + s;

    for(int i=0;i<=s.length()-1;i+=3)
    {       
        sum += (s[i]-'0') * 4;
        sum += (s[i+1]-'0') * 2;
        sum += (s[i+2]-'0') * 1;

        cout << sum;
        sum = 0;
        
    }

    return 0;
}