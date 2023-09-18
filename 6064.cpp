#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int t;
int m,n,x,y;

int main()
{
    FASTio;

    cin >> t;

    while(t--)
    {
        cin >> m >> n >> x >> y;

        int ans = -1;
        x--;  
        y--;

        for(int i=x;i<=n*m;i+=m)
        {
            if(i % n == y)
            {
                cout << i+1 << endl;
                ans = 1;
                break;
            }
        }
        if(ans == -1)
        {
            cout << -1 << endl;
        }


        
    }



    return 0;
}