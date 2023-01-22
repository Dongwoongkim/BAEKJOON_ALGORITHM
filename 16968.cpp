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
    int a = 10;
    int b = 26;
    int sum = 1;

    for(int i=0;i<s.length();)
    {   
        if(s[i]=='d')
        {   
            int index = i+1;
            int ori = a-1;
            sum *= a;
            while(1)
            {
                if(s[index]!='d')
                {
                    i = index;
                    break;
                }
                else
                {   
                    sum *= ori;
                    index++;
                } 
            }

        }
        else if(s[i]=='c')
        {
            int index = i+1;
            int ori = b-1;
            sum *= b;
            while(1)
            {
                if(s[index]!='c')
                {
                    i = index;
                    break;
                }
                else
                {   
                    sum *= ori;
                    index++;
                } 
            }
        }
    }

    cout << sum;

    return 0;
}