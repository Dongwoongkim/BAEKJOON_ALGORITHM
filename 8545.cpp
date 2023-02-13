#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
string s;
int main()
{
    FASTio;
    cin >> s;
    for(int i=s.length()-1;i>=0;i--)
    {
        cout << s[i];
    }
    return 0;
}