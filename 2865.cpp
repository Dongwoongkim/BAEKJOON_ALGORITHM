#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

int n,m,k;
map <int, double> e;
vector <double> v;
int cnt =0;
double sum;
int main()
{
    FASTio;

    cin>> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {   
            int num;
            double score;
            cin >> num >> score;
            e[num] = max(score,e[num]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        v.push_back(e[i]);
    }


    sort(v.begin(),v.end(),greater<>());

    for(int i=0;i<k;i++)
    {   
        sum += v[i];
    }

    cout << fixed;
    cout.precision(1);
    cout << sum;

    return 0;
}