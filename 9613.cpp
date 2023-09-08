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
int n;
long long sum =0;

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
}

int main()
{
    FASTio;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin >> v[i];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                sum += gcd(v[i],v[j]);
            }
        }

        cout << sum << endl;
        sum = 0;
    }


    return 0;
}