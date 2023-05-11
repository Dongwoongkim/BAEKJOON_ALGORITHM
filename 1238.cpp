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
int INF = 1000000000;
int ans = -1;

vector<pair<int,int>> v[1001];
vector<int> come(1001,0);

vector<int> d(1001,0);
void dijksta(int start)
{
    vector<bool> visited(1001,false);
    priority_queue<pair<int,int>> pq; // 힙
    
    pq.push(make_pair(start,0));

    while(!pq.empty()){
        int cur = pq.top().first;
        
        // 짧은것이 먼저오도록 음수화
        int distance = -pq.top().second;

        pq.pop();
        // 최단거리가 아닌 경우 스킵
        if(d[cur] < distance) continue;

        for(int i=0;i<v[cur].size();i++)
        {
            // 선택된 노드의 인접 노드
            int next = v[cur][i].first;
            // 선택된 노드 거쳐서 인접 노드로 가는 비용
            int nextDistance = v[cur][i].second + distance;

            // 기존의 최소 비용보다 저렴하면 교체
            if(nextDistance < d[next] && visited[cur]==false)
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
    
    for(int i=0;i<m;i++)
    {
        cin >> s >> e >> t;
        v[s].push_back(make_pair(e,t));
    }

    // i번째 집 -> x번째 집으로 가는 다익스트라 수행    
    for(int i=1;i<=n;i++)
    {  
        if(i==x) continue;

        // 초기화
        for(int j=1;j<=n;j++){
            d[j] = INF;
        }           
        dijksta(i);
        come[i] = d[x];
    
    }

    // x번째 집 -> i번째 집으로 돌아가는 다익스트라 수행
    for(int i=1;i<=n;i++)
    {
        d[i] = INF;
    }
    dijksta(x);

    for(int i=1;i<=n;i++)
    {
        come[i] += d[i]; 
    }

    // for(int i=1;i<=n;i++)
    // {
    //     cout << come[i] << ' ';
    // }
    // cout << endl;
    
    for(int i=1;i<=n;i++)
    {
        ans = max(come[i],ans);
    }

    cout << ans;

    return 0;
}