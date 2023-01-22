#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

int n;
int ans = -1;

/*
첫번째항, 두번째항 결정
-> 공차계산
-> 3번째항부터 공차와 같으면 continue;
->          공차-1 or 공차+1과 같으면 ans++;
*/

vector<int> a(100000);
int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    if(n==1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    for(int d1=-1;d1<=1;d1++)
    {
        for(int d2=-1;d2<=1;d2++)
        {   
            int cnt = 0;
            if(d1!=0) cnt++;
            if(d2!=0) cnt++;

            int a0 = a[0] + d1;
            int a1 = a[1] + d2;
            int diff = a1-a0;
            
            int an = a1 + diff;

            bool isit = true;

            // 2번째 항부터 검사
            for(int i=2;i<n;i++)
            {   
                if(a[i]==an)
                {
                    an +=diff;
                    continue;
                }

                if(a[i]-1==an) cnt++;
                else if(a[i]+1==an) cnt++;
                else
                {
                    isit = false;
                    break;
                }

                an += diff;
            }

            if(isit==true)
            {   
                if(ans==-1 || ans>cnt)
                    ans = cnt;
            }
        }
    }
    
    cout << ans << endl;



    return 0;
}