#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <cmath>

#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,s;
int ans = 1000000000;
vector<int> v(100001);
vector<int> p(100001);

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
}

int main()
{
    FASTio;
    cin >> n >> s;

    for(int i=0;i<n;i++){
        cin >> v[i];
        p[i] = abs(s-v[i]);
    }

    if(n==1)
    {
        cout << abs(s-v[0]);
        
    } else
    {
        ans = gcd(p[0],p[1]);

        for(int i=2;i<n;i++){
            ans = gcd(ans,p[i]);
        }

        cout << ans << endl;
    }

    return 0;
}