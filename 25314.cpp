#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int main()
{
    FASTio;
    int n;cin>>n;
    for(int i=4;i<=n;i+=4)
    {
        cout << "long ";
    }

    cout << "int";
    return 0;
}