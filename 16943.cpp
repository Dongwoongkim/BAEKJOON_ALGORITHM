#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
string a;
int b;
int ans = -1;

int main()
{
    FASTio;
    cin >> a >> b;

    sort(a.begin(),a.end());
    
    do{
        int c = stoi(a);
        if(a[0]!='0' && c < b)
        {
            ans = max(ans,c);
        } 
    }while(next_permutation(a.begin(),a.end()));

    cout << ans;

    return 0;
}