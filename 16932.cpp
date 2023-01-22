#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;


// 원본 배열 
vector <vector<int>> a(1001,vector<int>(1001));

// 그룹 크기 저장 배열
vector <vector<int>> b(1001,vector<int>(1001));

// 그룹 번호 저장
vector <vector<int>> g(1001,vector<int>(1001));

// 정답 배열
vector <vector<int>> r(1001,vector<int>(1001));


int n, m;
int groupnum = 1;
int ans = -1;
bool check[1001][1001];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void group(int y,int x,int groupnum)
{   
    int k = 1;
    queue<pair<int,int>> q;
    queue<pair<int,int>> nq;

    q.push(make_pair(y,x));
    nq.push(make_pair(y,x));
    g[y][x] = groupnum;
    check[y][x] = true;


    // 그룹 번호 지정
    while(!q.empty())
    {   
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && nx>=0 && ny<n && nx<m 
            && check[ny][nx]==false && a[ny][nx]==1)
            {   
                k++;
                check[ny][nx]=true;
                g[ny][nx] = groupnum;
                q.push(make_pair(ny,nx));
                nq.push(make_pair(ny,nx));
            }
        }
    }


    // 그룹 크기 b에 저장 
    while(!nq.empty())
    {
        int x = nq.front().second;
        int y = nq.front().first;
        b[y][x] = k;
        nq.pop();
    }

}

int main()
{
    FASTio;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }

    // 1번 - 그룹번호, 그룹크기 각각 g와 b배열에 저장
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   
            if(a[i][j]==1 && check[i][j]==false)
            {   
                group(i,j,groupnum);
                groupnum++;
            }
        }
    }

    // 2번 - 그룹번호를 이용해 방문하지 않은 그룹만 넓이계산해서 더해줌
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {   
                set<int> g_v;
        
                if(i+1<n && a[i+1][j]!=0 && g_v.find(g[i+1][j])== g_v.end())
                {   
                    g_v.insert(g[i+1][j]);
                    r[i][j] = max(r[i][j],r[i][j]+b[i+1][j]);
                }

                if(j+1<m && a[i][j+1]!=0 && g_v.find(g[i][j+1])== g_v.end())
                {
                    g_v.insert(g[i][j+1]);
                    r[i][j] = max(r[i][j],r[i][j]+b[i][j+1]);

                }
                if(i-1>=0 && a[i-1][j]!=0 && g_v.find(g[i-1][j])== g_v.end())
                {
                    g_v.insert(g[i-1][j]);
                    r[i][j] = max(r[i][j],r[i][j]+b[i-1][j]);

                }

                if(j-1>=0 && a[i][j-1]!=0 && g_v.find(g[i][j-1])== g_v.end())
                {   
                    g_v.insert(g[i][j-1]);
                    r[i][j] = max(r[i][j],r[i][j]+b[i][j-1]);
                }
            }
        }
    }


    // 3번 - 정답배열에서 가장 큰 값 = ans 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans = max(r[i][j]+1,ans);
        }

    }

    cout << ans;

    return 0;
}