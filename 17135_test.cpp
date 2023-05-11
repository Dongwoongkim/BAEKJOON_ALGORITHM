#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,m,d;
int ans = -1;
bool start[16];

// 좌 -> 상 -> 우
int dy[] = {0,-1,0};
int dx[] = {-1,0,1};
vector<vector<int>> v(16,vector<int>(16,0));

int bfs()
{
    int k = 0;
    vector<vector<int>> tmp;
    tmp.assign(v.begin(),v.end());
    
    vector<vector<bool>> kill(16,vector<bool>(16,false));

    for(int line = n ; line >=0 ; line--)
    {   
        // 궁수 한명씩 공격 
        for(int l=0;l<m;l++)
        {   
            if(start[l])
            {
                vector<vector<bool>> visited(16,vector<bool>(16,false));
                queue<pair<int,int>> q;
                q.push(make_pair(line,l));

                while(!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;

                    q.pop();

                    for(int i=0;i<3;i++)
                    {
                        // 다음 위치 
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        // 배열 범위중 안 간곳
                        if(ny>=0 && nx>=0 && ny<line && nx<m && visited[ny][nx]==false )
                        {   
                            // 사정거리 내부 
                            if(d >= (abs(ny-line) + abs(nx-l)))
                            {
                                // 적이 있는 경우 
                                if(tmp[ny][nx]==1)
                                {
                                    while(!q.empty())
                                    {
                                        q.pop();
                                    }
                                    // 같은 적이 여러명한테 공격당할 경우가 있으니 여기서 tmp 배열을 0으로 만들지 않고,
                                    // 적을 잡았다는 표시만 남겨두고 궁수 3명이 모두 공격한 이후에 0으로 세팅
                                    kill[ny][nx] = true;
                                    break;
                                }
                                // 적이 없는 경우
                                else
                                {
                                    q.push(make_pair(ny,nx));
                                    // 방문 처리 
                                    visited[ny][nx] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        // 궁수 한번씩 공격이 끝나면 잡은 적 수 확인
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(kill[i][j]==true) tmp[i][j] = 0;
            }
        }
    }
    // 모든 공격 후 잡은 적 수
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(kill[i][j]==true) k++;
        }
    }

    return k;
}

int main()
{
    FASTio;
    cin >> n >> m >> d;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> v[i][j];
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=i;j<m;j++)
        {
            for(int k=j;k<m;k++)
            {
                if(i!=j && j!=k)
                {
                    start[i] = true;
                    start[j] = true;
                    start[k] = true;

                    int k = bfs();
                    ans = max(k,ans);
                    memset(start,false,sizeof(start));
                
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}