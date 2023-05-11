#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

// 좌,상,우
int dx[]={-1,0,1};
int dy[]={0,-1,0};

bool check[16];
int n,m,dist;
int ans = -1;
vector<vector<int>> v(16,vector<int>(16,0));
vector<vector<int>> v_copy(16,vector<int>(16,0));
bool visited[16][16];

int bfs(vector<vector<int>> &v_copy)
{   
    int k = 0;
    bool kill[17][17];
    memset(kill, false, sizeof(kill));

    int pos = n;

    // n번의 공격 
    while(pos>0)
    {   
        // 궁수 세 명 한 턴씩 공격 
        for(int i=0;i<m;i++)
        {   
            // 궁수 한 명 
            if(check[i]==true)
            {   
                visited[pos][i] = true;
                queue<pair<int,int>> q;
                q.push(make_pair(pos,i));

                // 1턴 
                while(!q.empty())
                {   
                    // 궁수 좌표 
                    int y = q.front().first;
                    int x = q.front().second;

                    q.pop();

                    for(int i=0;i<3;i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        // 배열범위
                        if(ny>=0 && nx>=0 && ny<pos && nx < m)
                        {   
                            // 방문 X, 사정거리 내
                            if(visited[ny][nx] == false && dist >= (abs(ny-pos) + abs(nx-i)) )
                            {   
                                // 적 
                                if(v_copy[ny][nx] == 1)
                                {
                                    while(!q.empty())
                                    {
                                        q.pop();
                                    }   
                                    kill[ny][nx] = true;
                                    break;
                                }
                                q.push(make_pair(ny,nx));
                            }
                        }
                    }
                }
            }  
        }
        // 궁수 모두 한 번씩 공격 후
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<m;b++)
            {   
                if(kill[a][b] == true) v_copy[a][b] = 0;
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=0;b<m;b++)
            {   
                cout << v_copy[a][b] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        // 궁수가 위로 이동
        pos--;
    }


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
    cin >> n >> m >> dist;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> v[i][j];
        }
    }

     
    for(int a=0;a<m;a++)
    {
        for(int b=a;b<m;b++)
        {
            for(int c=b;c<m;c++)
            {                
                if(a!=b && b!=c && a!=c)
                {       
                    memset(check, false, sizeof(check));

                    check[a] = true;
                    check[b] = true;
                    check[c] = true;  
                    
                    v_copy.assign(v.begin(),v.end());
                    ans = max(ans,bfs(v_copy));
                    cout << ans << endl;


                }
            }
        }
    }

    cout << ans;


    return 0;
}