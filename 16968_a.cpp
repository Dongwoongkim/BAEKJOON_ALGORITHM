#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

string s;

int ans(int index, char before)
{   
    int sum = 0;

    if(s.length()==index)
    {
        return 1;
    }

    char start,end;

    if(s[index]=='c')
    {
        start = 'a';
        end = 'z';
    }
    else if (s[index]=='d')
    {
        start = '0';
        end = '9';
    }

    for(char c = start; c <= end ; c++)
    {
        if(c != before)
        {   
            sum += ans(index+1,c);
        }

    }

    return sum;
    

}
int main()
{
    FASTio;
    cin >> s;
    cout << ans(0,' ');
    return 0;
}