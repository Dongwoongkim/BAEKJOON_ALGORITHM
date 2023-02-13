#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n;
string s;
char Rcase='R';
char Bcase='B';
int ans = 0;
int Rcnt,Bcnt;
int main()
{
    FASTio;
    cin >> n;
    cin >> s;

    // Rcase

    for(int i=0;i<n;i++)
    {
        if(i==n-1 && s[i]=='R')
        {
            Rcnt++;
            break;
        }

        for(int j=i;j<n;j++)
        {   
            if(s[i]=='B') break;


            if(s[i]=='R')
            {
                if(s[j]=='R') continue;
                else if(s[j]=='B')
                {
                    i = j;
                    Rcnt++;
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(i==n-1 && s[i]=='B')
        {
            Bcnt++;
            break;
        }
    
        for(int j=i+1;j<n;j++)
        {   
            if(s[i]=='R') break;
            
            if(s[i]=='B')
            {
                if(s[j]=='B') continue;
                else if(s[j]=='R')
                {
                    i = j;
                    Bcnt++;
                    break;
                }
            }
        }
    }
    cout << min(Rcnt,Bcnt)+1 << endl;

    return 0;
}