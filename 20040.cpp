#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,m;
int from,to;
bool first;

vector<int> parent(5000000);
int ans = 0;
// 부모 찾기
int getParent(vector<int> &parent,int x){
    if(x == parent[x]) return x;

    else{
        return parent[x] = getParent(parent, parent[x]);
    }
}

void unionParent(vector<int> &parent, int a, int b)
{
    a = getParent(parent,a);
    b = getParent(parent,b);

    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int findParent(vector<int> &parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a==b) return 1;
    else return 0;
}


int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
    first = false;

    for(int i=1;i<=m;i++)
    {
        cin >> from >> to;
        if(!findParent(parent,from,to))
        {   
            unionParent(parent,from,to);
        }
        else if(findParent(parent,from,to) && first == false)
        {
            ans = i;
            first = true;
        }
    }
    cout << ans;

    return 0;
}
