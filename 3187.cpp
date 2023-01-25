#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
vector<vector<char>> area(250,vector<char>(250));
vector<vector<bool>> check(250,vector<bool>(250));

int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};
int ansS =0;
int ansW =0;


void bfs(int y,int x)
{   
    int sheep = 0;
    int wolf = 0;
    queue<pair<int,int>> q;

    q.push(make_pair(y,x));
    check[y][x]=true;

    if(area[y][x]=='v') wolf++;
    else if(area[y][x]=='k') sheep++;


    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && nx>=0 && ny<n && nx<m && area[ny][nx]!='#')
            {
                if(check[ny][nx]==false)
                {
                    if(area[ny][nx]=='v')
                    {
                        wolf++;
                        check[ny][nx] = true;
                        q.push(make_pair(ny,nx));
                    }

                    else if(area[ny][nx]=='k')
                    {
                        sheep++;
                        check[ny][nx] = true;
                        q.push(make_pair(ny,nx));
                    }
                    else if(area[ny][nx]=='.')
                    {
                        check[ny][nx] = true;
                        q.push(make_pair(ny,nx));
                    }

                }
            }
        }
    }

    if(sheep>wolf)
    {
        wolf = 0;
    }
    else
    {
        sheep = 0;
    }

    ansS += sheep;
    ansW += wolf;

}
int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> area[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {    
            if(area[i][j]!='#' && check[i][j]==false)
            {
                bfs(i,j);
            }
        }
    }

    cout << ansS << ' ' << ansW;
    return 0;
}