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

    getline(cin,s);


    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {   
            if((int)s[i]<110)
                cout << char((int)s[i]+13);
            else
                cout << char((int)s[i]-13);
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            if((int)s[i]<78)
                cout << char((int)s[i]+13);
            else
                cout << char((int)s[i]-13);
        }
        else cout << s[i];
    }



    return 0;
}