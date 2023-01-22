#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;

int dx[] ={0,1,0,-1};
int dy[] ={1,0,-1,0};
// 우 , 하 , 좌 , 상 

vector<vector<int>> a(10,vector<int>(10));
vector<int> dirs;
vector<tuple<int,int,int>> cctv;

/* 감시방법
1번 상 or 하 or 좌 or 우
2번 좌우 or 상하
3번 상우 or 우하 or 좌하 or 상좌 
4번 좌상우 or 상우하 or 좌우하 or 상좌하 
5번 상하좌우 

cctv개수 최대 8개이므로 O(4^8)

1) cctv 방향 65536 
2) 사각지대 크기 O(nm)

총 시간복잡도는 O(65536 * n * m )

*/


void check(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y, int dir)
{
    int i = x;
    int j = y;

    // 범위 안에 있으면서
    while(0<=i && 0<=j && i<n && j<m)
    {   
        // 6이 아닐때까지 채워준다
        if(a[i][j]==6) break;
        b[i][j] = a[x][y];
        i += dx[dir];
        j += dy[dir];
    }
}

int go(int index)
{   
    if(cctv.size()==index)
    {   
        int cnt = 0;
        vector<vector<int>> b(a);
        for(int i=0;i<cctv.size();i++)
        {   
            // what = cctv 번호 , x = 행, y= 열
            int what,x,y;
            tie(what,x,y)=cctv[i];
            
            // 1번 상 or 하 or 좌 or 우
            if(what==1)
            {
                check(a,b,x,y,dirs[i]);
            }
            // 2번 좌우 or 상하

            else if(what==2)
            {
                check(a,b,x,y,dirs[i]);
                check(a,b,x,y,(dirs[i]+2)%4);
            }

            // 3번 상우 or 우하 or 좌하 or 상좌 
            else if(what==3)
            {
                check(a,b,x,y,dirs[i]);
                check(a,b,x,y,(dirs[i]+1)%4);
            }

            // 4번 좌상우 or 상우하 or 좌우하 or 상좌하 
            else if(what==4)
            {
                check(a,b,x,y,dirs[i]);
                check(a,b,x,y,(dirs[i]+1)%4);
                check(a,b,x,y,(dirs[i]+2)%4);
            }
            // 상하좌우
            else if(what==5)
            {
                check(a,b,x,y,dirs[i]);
                check(a,b,x,y,(dirs[i]+1)%4);
                check(a,b,x,y,(dirs[i]+2)%4);
                check(a,b,x,y,(dirs[i]+3)%4);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i][j]==0) cnt++;
            }
        }

        return cnt;


    }

    // 최대 8*8 = 64니까 넉넉잡아 100으로 설정
    int ans = 100;
    
    // index번째 cctv의 방향 결정
    for(int i=0;i<4;i++)
    {   
        // index번째 회전 총 4번(i)
        dirs[index]=i;
        int tmp = go(index+1);

        if(ans> tmp)
        {
            ans = tmp;
        }
    }

    return ans;

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
            if(a[i][j]>=1 && a[i][j] <=5)
            {
                // 번호, 행, 열
                cctv.emplace_back(a[i][j],i,j);
                // 90도 회전수를 담아줌
                dirs.push_back(0);
            }
        }
    }

    cout << go(0) << endl;

    return 0;
}