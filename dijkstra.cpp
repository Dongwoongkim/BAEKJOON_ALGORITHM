#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n = 6;
int INF = 1000000000;

int a[6][6] = {
    {0,2,5,1,INF,INF},
    {2,0,3,2,INF,INF},
    {5,3,0,3,1,5},
    {1,2,3,0,1,INF},
    {INF,INF,1,1,0,2},
    {INF,INF,5,INF,2,0},
};

vector <bool> visited(6,false); 
vector <int> d(6,0); // 최단거리 기록


// 가장 최소거리를 가지는 정점 리턴
int getSmallIndex()
{
    int min = INF;
    int idx = 0;

    for(int i=0;i<n;i++)
    {
        if(d[i]<min && visited[i]==false){
            min = d[i];
            idx = i;
        }
    }
    return idx;
}

// 다익스트라 
void dijkstra(int start){
    for(int i=0;i<n;i++){
        d[i] = a[start][i];
    }
    visited[start]=true;
    
    for(int i=0;i<n-1;i++)
    {
        int cur = getSmallIndex();
        visited[cur] = true;
        
        for(int j=0;j<6;j++){
            if(!visited[j]){
                if(d[cur] + a[cur][j] < d[j]){
                    d[j] = d[cur] + a[cur][j];
                }
            }
        }
    }
}

int main()
{
    FASTio;
    dijkstra(0);
    for(int i=0;i<n;i++)
    {
        cout << d[i] << ' ';
    }

    return 0;
}