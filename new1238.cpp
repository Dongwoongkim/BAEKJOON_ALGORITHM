#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

int n,m,x;
int s,e,t;
const int INF = 1000000000;


vector<pair<int,int>> v[1001];
vector<int> come(1001,0);

vector<int> d(1001,0);


void dijksta(int start)
{
    d[start]=0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(start,0));

    while(!pq.empty())
    {
        int cur = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[cur] < distance) continue;

        for(int i=0;i<v[cur].size();i++)
        {
            int next = v[cur][i].first;
            int nextDistance = v[cur][i].second + distance;
            if(nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }
        }
    }
}
int main()
{
    FASTio;
    cin >> n >> m >> x;

    // 100만
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &s,&e,&t);
        v[s].push_back(make_pair(e,t));
        v[e].push_back(make_pair(s,t));
    }

    // 50만 
    for(int i=1;i<=n;i++){
        d[i] = INF;
    }
    
    // 100만 (log 50만)
    dijksta(x);
    
    // 50만 
    for(int i=1;i<=n;i++){
        if(d[i] == INF) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
    return 0;
}