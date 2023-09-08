#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int num;
int t;
int n = 1000001;
int arr[1000001];
vector<bool> check(1000001,false);

int main()
{
    FASTio;

    for(int i=2;i<=n;i++)
    {
        arr[i] = i;
    }

    for(int i=2; i<=n ;i++)
    {
        if(arr[i]==0) continue;

        for(int j=2*i;j<=n;j+=i)
        {
            arr[j] = 0;
        }
    }

    cin >> t;

    for(int i=0;i<t;i++)
    {   
        int cnt = 0;
        cin >> num;
        bool wrong = true;
        vector<bool> check(1000001,false);
        for(int a=2;a<=num;a++)
        {   
            if(arr[a] != 0 && arr[num-a] !=0 && !check[a] && !check[num-a])
            {
                check[num-a] = true;
                check[a] = true;
                cnt++;
            } 
        
        }

        cout << cnt << endl;

    }
    



    return 0;
}