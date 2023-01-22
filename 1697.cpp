#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,k;
int ans = 0;
queue<pair<int,int>> q;
bool check[100001];

void bfs(int n)
{   
    q.push(make_pair(n,0));

    check[n] = true;

    while(!q.empty())
    {
        int data = q.front().first;
        int depth = q.front().second;


        int first = q.front().first - 1;
        int second = q.front().first + 1;
        int third = q.front().first * 2;

        q.pop();


        if(data == k)
        {
            ans = depth;
            break;
        }

        if(first >= 0 && first <= 100000 && check[first]==false)
        {   
            q.push(make_pair(first,depth+1));
            check[first] = true;
        }

        if(second >= 0 && second <= 100000 && check[second]==false)
        {
            q.push(make_pair(second,depth+1));
            check[second] = true;
        }

        if(third >= 0 && third <= 100000 && check[third]==false)
        {
            q.push(make_pair(third,depth+1));
            check[third] = true;
        }
    }
}
int main()
{    
    FASTio;
    cin >> n >> k;
    
    bfs(n);

    cout << ans << endl;
    

    return 0;
}