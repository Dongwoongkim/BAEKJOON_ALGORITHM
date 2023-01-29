#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

int f,s,g,u,d;
int cnt = 1;
int visited[1000001];
bool check[1000001];

bool bfs(int index)
{
    queue <int> q;
    q.push(index);
    while(!q.empty())
    {   
        int k = q.front(); 
        

        if(k==g)
        {   
            cout << visited[k]-1;
            return false;
        }
        
        if(k+u<=f)
        {   
            if(visited[k+u]==0)
            {
            q.push(k+u);
            visited[k+u] = visited[k] + 1;
            }
        }

        if(k-d>0)
        {
            if(visited[k-d]==0)
            {
            q.push(k-d);
            visited[k-d] = visited[k] + 1;
            }
        }
        q.pop();
    }
    
    return true;
}

int main()
{
    FASTio;
    cin >> f >> s >> g >> u >> d;

    visited[s]= 1;
    
    if(g==s) {
        cout << 0;
        return 0;
    }
    bool stare = bfs(s);
    if(stare)
    cout << "use the stairs";
    

    return 0;
}