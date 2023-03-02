#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,ans,t;
int arr[1001];
vector<pair<int,int>> v;
int sum;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}


int main()
{

    FASTio;
    cin >> n;
    for(int i=1;i<=n;i++)
    {   
        cin >> t;
        v.push_back(make_pair(i,t));
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++)
    {
        ans+= v[i].second;
        sum += ans;
    }

    cout << sum;

    return 0;
}