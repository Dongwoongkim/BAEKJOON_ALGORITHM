#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n;
vector <int> arr(20);
vector <bool> check(100000*20+10);
int main()
{
    FASTio;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<(1<<n);i++)
    {
        int sum = 0;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                sum += arr[j];
        }
        cout << sum << endl;
        check[sum]=true;
    }


    


    return 0;
}