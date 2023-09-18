#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
long long a,b;

int main()
{
    FASTio;
    cin >> a >> b;
    cout << (a+b)*(a-b);
    return 0;
}