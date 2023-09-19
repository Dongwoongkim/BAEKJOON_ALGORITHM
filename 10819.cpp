#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;


int n;

int main()
{
    FASTio;
    cin >> n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    int ans = -1;
    do{
        int sum = 0;
        for(int i=0;i<n-1;i++)
        {
            sum += abs(v[i]-v[i+1]);
        }

        ans = max(sum,ans);

    }while(next_permutation(v.begin(),v.end()));

    cout << ans;


    return 0;
}