#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int main()
{
    FASTio;

    int start,end;
    int t;
    cin >> t;

    for(int i=0;i<t;i++) 
    {
        cin >> start >> end;
        int cnt=0;
        int d = end-start;
        int max =  (int)(sqrt(d));
        if(max==(sqrt(d)))
        {
            cnt = 2*max-1;
        }
        else if(d<=max*max+max)
        {
            cnt = 2*max;
        }
        else
        {
            cnt = 2*max+1;
        }
            cout << cnt << endl;
    }

    return 0;
}
