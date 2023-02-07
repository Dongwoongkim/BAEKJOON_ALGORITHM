#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int bfs(int n, int m, int y,int x,int desty,int destx,vector<vector<char>>&area)
{
    vector<vector<int>> visited(n+1,vector<int>(m+1,0));
    vector<vector<bool>> check(n+1,vector<bool>(m+1,false));
    check[y][x] = true;
    queue <pair<int,int>> q;
        
    q.push(make_pair(y,x));

    while(!q.empty())
    {   
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y==desty && x==destx)
        {   
            break;
        }
        else
        {
            for(int k=0;k<4;k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if(ny>=0 && nx>=0 && ny<n && nx<m)
                {
                    if(area[ny][nx]!='x' && check[ny][nx]==false)
                    {   
                        check[ny][nx]=true;
                        q.push(make_pair(ny,nx));
                        visited[ny][nx] = visited[y][x]+1;
                    }
                }
            }
        }
    }

    return visited[desty][destx];
}

int main()
{
    FASTio;

    while(1)
    {
        cin >> m >> n;
        if(n==0 && m==0) break;
        else
        {   
            vector<vector<char>> area(n+1,vector<char>(m+1));
            vector<pair<int,int>> v(1);

            int ans = -1;

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cin >> area[i][j];
                    if(area[i][j]=='o')
                    {
                        v[0] = make_pair(i,j);
                    }

                    else if(area[i][j]=='*')
                    {   
                        v.push_back(make_pair(i,j));
                    }
                }
            }

            vector<vector<int>> dust_dist(v.size(),vector<int>(v.size(),0));

            // 로봇청소기 -> *까지의 거리 모두 계산해서 저장
            for(int i=1;i<v.size();i++)
            {
                int dist = bfs(n,m,v[0].first,v[0].second,v[i].first,v[i].second,area); 
                dust_dist[0][i] = dist;
            }
        
            // *들 간의 거리
            for(int i=1;i<v.size();i++)
            {
                for(int j=1;j<v.size();j++)
                {
                    dust_dist[i][j] = bfs(n,m,v[i].first,v[i].second,v[j].first,v[j].second,area);
                }
            }

            vector<int> order(v.size()-1);

            for(int i=0;i<order.size();i++)
            {
                order[i] = i+1;
            }

            sort(order.begin(),order.end());
            
            do
            {   
                bool itcant = false;

                int sum = dust_dist[0][order[0]];


                // 첫번째 *로 못가면 다음 조합 살펴보기
                if(sum==0)
                {
                    continue;
                }


                for(int i=0;i<order.size()-1;i++)
                {   
                    // * -> * 못가면 종료
                    if(dust_dist[order[i]][order[i+1]]==0)
                    {
                        itcant = true;
                        break;
                    }

                    // sum에 먼지거리 더해주기
                    sum += dust_dist[order[i]][order[i+1]];
                }    

                if(itcant==true)
                {
                    continue;
                }


                else
                {  
                   
                   if(ans==-1 || ans>sum)
                   {
                   ans = sum;
                   }
                }

            } while (next_permutation(order.begin(),order.end()));

            cout << ans << endl;
        }

    }


    return 0;
}