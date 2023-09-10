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

long long arr[1000001];

long long fibo(int n)
{
    if(n==1 || n==0)
    {
        return n;
    }
    
    else 
    {
        if(arr[n] > 0)
        {
            return arr[n];
        }
        else
        {
            arr[n] = (fibo(n-1) + fibo(n-2))%1000000000;
            return arr[n];
        }
    }
}


int main()
{
    FASTio;

    cin >> n;

    if(n<0)
    {   
        if((-n)%2==1){
            cout << 1 << endl;
        }
        else {
            cout << -1 << endl;
        }

    } else if(n==0){
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    if(n<0)
    cout << fibo(-n);
    else
    {
        cout << fibo(n);
    }



    return 0;
}