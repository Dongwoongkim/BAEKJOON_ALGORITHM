#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int r,c;
vector<vector<char>> map(501,vector<char>(501));
// 좌, 우, 하, 상
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    FASTio;
    cin >> r >> c;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]=='S')
            {   
                for(int k=0;k<4;k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny>=0 && nx>=0 && ny<r && nx<c)
                    {
                        if(map[ny][nx]=='W')
                        {
                            cout << 0;
                            return 0;
                        }
                    }
                } 
            }
        }
    }

    cout << 1 << endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]=='.')
            {   
                map[i][j]='D';
            }
            cout << map[i][j];
        }
        cout << endl;
    }


    return 0;
}