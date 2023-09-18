#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

vector<int> v(9,0);
int main()
{
    FASTio;

    int sum = 0;

    for(int i=0;i<9;i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    bool find = false;
    for(int i=0;i<9;i++)
    {   
        int sumTmp = sum;
        
        sumTmp -= v[i];

        for(int j=i+1;j<9;j++)
        {
            if(sumTmp-v[j]==100)
            {   
                v[i] = -1;
                v[j] = -1;
                find = true;
                break;
            }
        }

        if(find)
        {
            break;
        }
    }

    sort(v.begin(),v.end());

    for(int i=0;i<9;i++)
    {   
        if(v[i]==-1) continue;
        cout << v[i] << endl;
    }


    return 0;
}