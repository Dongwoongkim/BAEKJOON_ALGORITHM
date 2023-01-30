
/* 1번코드입니다 (AC)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int hdy[] = {-1,-2,-2,-1,1,2,1,2};
int hdx[] = {-2,-1,1,2,-2,-1,2,1};

vector<vector<int>> v(201,vector<int>(201));
int check[201][201][31];
int k,w,h;

int bfs(int y,int x)
{
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(make_pair(make_pair(y,x),make_pair(0,0)));
    check[y][x][0] = true;

    while(!q.empty())
    {   
        // ( 현재 y좌표 , 현재 x좌표 , 현재 horse moving 사용횟수, 현재 총 동작 수)
        int y = q.front().first.first;
        int x = q.front().first.second;
        int hm = q.front().second.first;
        int ans = q.front().second.second;

        q.pop();

        if(y==h-1 && x==w-1)
        {   
            return ans;
        }


        // 일반 동작 (상하좌우)
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny>=0 && nx>=0 && nx<w && ny<h)
            {   
                // 다음좌표 (nx,ny)에 특정동작 사용하지않고 일반동작을 사용하여 방문해보지 않았으면 방문해본다.
                if(check[ny][nx][hm]==false && v[ny][nx]==0)
                {                                                  // 총 동작횟수
                    q.push(make_pair(make_pair(ny,nx),make_pair(hm,ans+1)));
                    
                    // (nx,ny)좌표에 총 특정동작 hm번 사용해서 방문했다는 뜻 
                    check[ny][nx][hm] = true;

                }
            }
        }


        // 특정 동작 (홀스 무빙) 최대 k번 사용가능 
        if(hm<k)
        {
            for(int i=0;i<8;i++)
            {
                int ny = y + hdy[i];
                int nx = x + hdx[i];

                if(ny>=0 && nx>=0 && nx<w && ny<h)
                {   
                    // 다음 좌표 ny,nx에 특정동작 사용하여 이동하지 않았으면 이동해본다.
                    if(check[ny][nx][hm+1]==false && v[ny][nx]==0)
                    {   
                                                                         //총 동작 횟수 
                        q.push(make_pair(make_pair(ny,nx),make_pair(hm+1,ans+1)));
                         
                        // (nx,ny)좌표에 총 특정동작+1번 사용해서 방문했다는 뜻 
                        check[ny][nx][hm+1] = true;
                    }
                }
            }
        }
    }


    // 목적지에 도달하지 못한경우 -1 리턴
    return -1;
}

int main()
{
    FASTio;
    cin >> k >> w >> h;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> v[i][j];
        }
    }
    cout << bfs(0,0);


    return 0;
}

/* 2번코드입니다 (메모리초과)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int hdy[] = {-1,-2,-2,-1,1,2,1,2};
int hdx[] = {-2,-1,1,2,-2,-1,2,1};

vector<vector<int>> v(201,vector<int>(201));
int check[201][201][31];
int k,w,h;

int bfs(int y,int x)
{
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(make_pair(make_pair(y,x),make_pair(0,0)));

    while(!q.empty())
    {   
        // ( 현재 y좌표 , 현재 x좌표 , 현재 horse moving 사용횟수, 동작 수)
        int y = q.front().first.first;
        int x = q.front().first.second;
        int hm = q.front().second.first;
        int ans = q.front().second.second;


        // (x,y)좌표에 특정동작 hm번 사용해서 방문했다는 뜻 
        check[y][x][hm] = true;

        q.pop();

        if(y==h-1 && x==w-1)
        {   
            return ans;
        }


        // 일반 동작 (상하좌우)
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny>=0 && nx>=0 && nx<w && ny<h)
            {   
                // 다음좌표 (nx,ny)에 특정동작 사용하지않은 일반동작을 사용하여 방문해보지 않았으면 방문해본다.
                if(check[ny][nx][hm]==false && v[ny][nx]==0)
                {                                                  // 총 동작횟수
                    q.push(make_pair(make_pair(ny,nx),make_pair(hm,ans+1)));
                }
            }
        }


        // 특정 동작 (홀스 무빙) 최대 k번 사용가능 
        if(hm<k)
        {
            for(int i=0;i<8;i++)
            {
                int ny = y + hdy[i];
                int nx = x + hdx[i];

                if(ny>=0 && nx>=0 && nx<w && ny<h)
                {   
                    // 다음 좌표 ny,nx에 특정동작 사용하여 이동하지 않았으면 이동해본다.
                    if(check[ny][nx][hm+1]==false && v[ny][nx]==0)
                    {   
                                                                         //동작 횟수 
                        q.push(make_pair(make_pair(ny,nx),make_pair(hm+1,ans+1)));
                    }
                }
            }
        }
    }
    // 목적지에 도달하지 못한경우 -1 리턴
    return -1;
}

int main()
{
    FASTio;
    cin >> k >> w >> h;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> v[i][j];
        }
    }
    cout << bfs(0,0);


    return 0;
}
