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
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {
            cout << i << j << endl;
            i = j;
        }
    }
    return 0;
}