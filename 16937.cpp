#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

// 스티커 2개 고르는 경우 nC2 ~= n^2
// 회전가능하니까 각경우 2개 = 2*2 = 4
// 가로로붙히기, 세로로붙히기 = 2개
// 최대 경우의 수 8n^2  

int ans = 0;
int h,w,n;
int r[101],c[101];
int main()
{
    FASTio;
    cin >> h >> w >> n;
    
    for(int i=0;i<n;i++)
    {
        cin >> r[i] >> c[i];
    }

    for(int i=0;i<n;i++) // 1번스티커
    {   
        int r1 = r[i];
        int c1 = c[i];

        for(int j=i+1;j<n;j++) // 2번스티커
        {
            int r2 = r[j];
            int c2 = c[j];
            
            for(int rot1=0;rot1<2;rot1++) // 1번 90도 회전
            {
                for(int rot2=0;rot2<2;rot2++) // 2번 90도 회전
                {
                    if(r1+r2 <= w && max(c1,c2) <= h)
                    {
                        int tmp = r1*c1 + r2*c2;
                        ans = max(ans,tmp);
                    }
                    
                    if(c1+c2 <= h && max(r1,r2) <= w)
                    {
                        int tmp = c1*r1 + c2*r2;
                        ans = max(ans,tmp);
                    }
                    swap(r2,c2);
                }
                swap(r1,c1);
            }
        }
    }

    cout << ans;


    return 0;
}