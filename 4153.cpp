#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int a,b,c;
int main()
{
    FASTio;
    while(1)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        if(v[0]==0 && v[1]==0 && v[2]==0) break;

        sort(v.begin(),v.end());

    if(v[2]*v[2]==v[0]*v[0]+v[1]*v[1])
    {
        cout<<"right" << endl;
    }
    else cout << "wrong" << endl;

    }
    return 0;
}