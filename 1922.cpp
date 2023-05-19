#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,m;
int from,to,cost;
vector<pair<int,pair<int,int>>> v;
vector<int> parent(1000);

int getParent(vector<int> &parent, int x){
    if(parent[x]==x) return x;
    else{
        return parent[x] = getParent(parent, parent[x]);
    }
}

void unionParent(vector<int> &parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);

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

    for(int i=1;i<=n;i++){
        parent[i] = i;
    } 

    for(int i=0;i<m;i++)
    {
        cin >> from >> to >> cost;
        v.push_back(make_pair(cost,make_pair(from,to)));
    }
    sort(v.begin(),v.end());

    int sum = 0;
    for(int i=0;i<v.size();i++){
        // 사이클이 발생하지 않는 경우만
        if(!findParent(parent, v[i].second.first, v[i].second.second))
        {
            sum += v[i].first;
            unionParent(parent, v[i].second.first, v[i].second.second);
        }
    }

    cout << sum <<endl;
    
    
    return 0;
}
