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
int n = 1000001;
int arr[1000001];

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

    cin >> num;

    while(num)
    {   
        bool wrong = true;
        for(int a=3;a<=num;a+=2)
        {   
            if(arr[a] != 0 && arr[num-a] !=0)
            {
                wrong = false;
                cout << num << " = " << a  << " + " << num-a << endl;
                break;
            } 
        }

        if(wrong)
        {
            cout << "Goldbach's conjecture is wrong." << endl;
        }

        cin >> num;
    }
    



    return 0;
}