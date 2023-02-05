#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

vector<vector<char>> area(51,vector<char>(51));
vector<vector<int>> b(51,vector<int>(51));
vector<pair<int,int>> v;
int n,m;
int st=-1;
int en=-1;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int main()
{
    FASTio;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> area[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(area[i][j]=='#')
            {   
                // 시작점 - 거울.... - 끝점 기록
                if(st==-1)
                {   
                    st = v.size();
                }

                else 
                {
                    en = v.size();
                }

                // 벽 좌표 기록
                v.push_back(make_pair(i,j));

                // (i,j)의 벽 번호 기록 
                b[i][j] = v.size()-1;
            }

            else if(area[i][j]=='!')
            {   
                // 거울 좌표 기록
                v.push_back(make_pair(i,j));
                
                // (i,j)의 거울의 번호 기록
                b[i][j] = v.size()-1;
            }
        }
    }
    m = v.size();

    vector<vector<bool>> check(m,vector<bool>(m,false));

    for(int i=0;i<m;i++)
    {
        for(int k=0;k<4;k++)
        {   
            int ny = v[i].first + dy[k];
            int nx = v[i].second + dx[k];
            while(ny>=0 && nx>=0 && ny<n && nx<n)
            {   
                // 벽 만나면 종료
                if(area[ny][nx]=='*') break;

                // 위로 쭉 보고 있으면 경로 check -> 아래로쭉보고 있으면 경로 check -> 좌 ... -> 우..
                if(area[ny][nx]=='!' || area[ny][nx]=='#')
                {   
                    // i번 거울에서 다음 거울의 번호로 가는 경로 check
                    check[i][b[ny][nx]]=true;
                    cout << i << ' ' << b[ny][nx] << endl;

                }
                ny += dy[k];
                nx += dx[k];    
            }
        }
    }

    queue<int>q;
    q.push(st);
    vector<int> dist(m,-1);
    dist[st]=0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0;i<m;i++)
        {    
            if(check[now][i] && dist[i]==-1)
            {   
                dist[i] = dist[now]+1;
                q.push(i);

            }
        }
    }
    cout << dist[en]-1;
    return 0;
}