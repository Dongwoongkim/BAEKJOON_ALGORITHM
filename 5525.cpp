#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

int n;
int l;
int ans;
string s;

int main()
{
    FASTio;
    cin >> n;
    cin >> l;
    cin >> s;

    for(int i=0;i<s.length();i++)
    {   
        if(s[i]=='I')
        {   
            int k = 0;
            while(1)
            {
                if(s[i+1]=='O' && s[i+2]=='I')
                {
                    k++;
                    i+=2;
                }
                else
                {
                    break;
                }
    
                if(k==n)
                {
                    k--;
                    ans++;
                }
                
            }
        }
        
    }

    cout << ans;    
    return 0;
}