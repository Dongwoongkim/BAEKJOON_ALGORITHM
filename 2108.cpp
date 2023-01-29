#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,num;
int m=-1;
int mi=-1;
int sum=0;
vector<int> v;
int arr[8002];

int main()
{
    FASTio;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        sum += num;
        arr[num+4000]++;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<8002;i++)
    {
        if(arr[i]>m)
        {
            m = arr[i];
            mi = i;
        }
    }


    cout << sum/n << endl;
    cout << v[n/2] << endl;

   
    cout << mi-4000 << endl;

    cout << v[n-1]-v[0] << endl; 


    return 0;
}
