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
    vector<int> input(n,0);
    for(int i=0;i<n;i++) cin >> input[i];

    if(prev_permutation(input.begin(),input.end()))
    {
        for(int i=0;i<n;i++)
        {
            cout << input[i] << ' ';
        }
    } else
    {
        cout << -1;
    }

    return 0;
}