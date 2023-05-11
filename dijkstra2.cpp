#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
vector <pair<int,int>> v[1000]; // 간선 정보
int d[7]; // 최소 비용

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int,int>> pq; // 힙구조

    // 가까운 순서대로 처리 
    while(!pq.empty()){
        int cur = pq.top().first; // 가장 적은 비용을 갖는 노드 선택
        // 짧은것이 먼저오도록 음수화
        int distance = -pq.top().second;
        pq.pop();

        // 최단거리가 아닌 경우 스킵
        if(d[cur] < distance) continue;
        for(int i=1;i<=v[cur].size();i++)
        {
            // 선택된 노드의 인접 노드
            int next = v[cur][i].first; 
            // 선택된 노드 거쳐서 인접 노드로 가는 비용
            int nextDistance = v[cur][i].second + distance;

            // 기존의 최소 비용보다 저렴하면 교체
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

    return 0;
}