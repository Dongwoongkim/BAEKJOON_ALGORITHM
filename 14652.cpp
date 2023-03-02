#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
long long n,m,k;
int main()
{
    FASTio;
    cin >> n >> m >> k;

    cout << k/m << ' ' << k%m;
    return 0;
}