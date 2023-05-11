#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;
vector<int> v(10,0);
int main()
{
    FASTio;
    cin >> n;
    for(int i=0;i<n;i++)
    {   
        for(int i=0;i<10;i++)
            cin >> v[i];
        
        sort(v.begin(),v.end());
        cout << v[7] << endl;
    }
    return 0;
}