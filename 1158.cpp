#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n, k;

queue<int> q;

int main()
{
    FASTio;
    cin >> n >> k;

    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }

    cout << "<";
    while(!q.empty()){

        for(int i=0;i<k-1;i++)
        {
            int k = q.front();

            q.pop();
            q.push(k);
        }

        if(q.size() == 1)
        {
            cout << q.front() << ">";
        } else {
            cout << q.front() << ", ";
        }

        q.pop();
        
    }

    return 0;
}