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
    int x=1;
    int y=6;

    while(y--)
    {
        x++;
    }

    cout << x << ' ' << y;
    return 0;
}