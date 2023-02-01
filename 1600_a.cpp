#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int k,h,w;
vector < vector<int> > area(201, vector<int>(201));

bool check[201][201][31];
int dy[]={-1,1,0,0,-1,-2,-2,-1,1,2,2,1};
int dx[]={0,0,-1,1,-2,-1,1,2,-2,-1,1,2};

int bfs(int y,int x)
{   
    queue< pair< pair<int,int>,pair<int,int>>>q;
    
    // (y좌표,x좌표), (horse무빙 횟수, 총 무빙 횟수)
    q.push(make_pair(make_pair(y,x),make_pair(0,0)));
    check[y][x][0]=true;

    while(!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int hcnt = q.front().second.first;
        int cnt = q.front().second.second;

        q.pop();

        if(y==h-1 && x==w-1)
        {
            return cnt;
        }

        for(int i=0;i<12;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny>=0 && nx>=0 && ny<h && nx<w && area[ny][nx]==0)
            {   

                // horse moving 사용
                if(hcnt<k && i>=4 && check[ny][nx][hcnt+1]==false)
                {   
                    check[ny][nx][hcnt+1] = true;
                    q.push(make_pair(make_pair(ny,nx),make_pair(hcnt+1,cnt+1)));
                }
                

                // monkey monving 사용
                if(i<4 && check[ny][nx][hcnt]==false)
                {
                    check[ny][nx][hcnt] = true;
                    q.push(make_pair(make_pair(ny,nx),make_pair(hcnt,cnt+1)));
                }
            }
        }

    }

    return -1;
}

int main()
{
    FASTio;
    cin >> k >> w >> h;

    // Input
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> area[i][j];
        }
    }

    int ans = bfs(0,0);
    cout << ans;

    return 0;
}