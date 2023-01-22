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

int n, m;
int ans = 0;
int cnt = 0;
bool check[1001][1001];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void bfs(int y,int x)
{   
    int k = 1;
    queue<pair<int,int>> q;

    q.push(make_pair(y,x));
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
                q.push(make_pair(ny,nx));
            }
        }
    }


    ans = max(ans,k);

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
                check[i][j] = true;
                bfs(i,j);
                cnt++;
            }
        }
    }


    cout << cnt << endl;
    cout << ans;


    return 0;
}