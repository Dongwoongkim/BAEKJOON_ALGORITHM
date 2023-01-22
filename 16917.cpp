#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int a,b,c,x,y;
int ans,ans2,ans3;

int main()
{
    FASTio;
    cin >> a >> b >> c >> x >> y;

    int ans = a*x + b*y;

    if(x>=y)
    {
        ans2 = y*c*2 + (x-y)*a;
        ans3 = c*x*2;
    }
    else if(x<y)
    {
        ans2 = x*c*2 + (y-x)*b;
        ans3= c*y*2;
    }

    ans = min(ans,min(ans2,ans3));

    cout << ans << endl;

    return 0;
}