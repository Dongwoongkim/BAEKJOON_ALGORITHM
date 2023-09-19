#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,m;

bool broken[11];

int check(int num)
{   
    int tmp = num;
    if(tmp==0)
    {
        if(broken[0]) return 1;
        else
            return 0;
    }

    while(tmp)
    {
        int k = tmp%10; 
        if(broken[k]) return 1;
    
        tmp/=10;
    
    }

    return 0;
}

int length(int num)
{   
    if(num==0) return 1;
    
    int cnt = 0;

    while(num)
    {
        num/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    FASTio;
    cin >> n;
    cin >> m;

    int ans = abs(n-100);

    for(int i=0;i<m;i++)
    {
        int brokenNum;
        cin >> brokenNum;
        broken[brokenNum] = true;
    }

    for(int i=0;i<=1000000;i++)
    {   
        if(check(i)) 
        {   
            continue;
        }
        else
        {   
            ans = min(ans, length(i) + abs(n-i));
        }
    }

    cout << ans;


    return 0;
}