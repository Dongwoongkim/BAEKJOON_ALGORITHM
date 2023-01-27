#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;

vector<vector<char>> area(16,vector<char>(16));
int ans = -1;
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

    for(int y1=0;y1<n;y1++)
    {   
        for(int x1=0;x1<m;x1++)
        {   
            if(area[y1][x1]=='#')
            {   
                // 십자가 1
                for(int l=0;;l++)
                {   
                    // 범위밖
                    if(x1-l < 0 || x1+l >=m || y1-l < 0 || y1+l >=n) break;
                    if(area[y1][x1+l]!='#' || area[y1+l][x1]!='#' || area[y1][x1-l]!='#' || area[y1-l][x1]!='#') break;
                    
                    area[y1][x1+l]='*'; 
                    area[y1][x1-l]='*'; 
                    area[y1+l][x1]='*'; 
                    area[y1-l][x1]='*';

                    int area2=1;
                    // 십자가 2 
                    for(int y2=0;y2<n;y2++)
                    {  
                        for(int x2=0;x2<m;x2++)
                        {   
                            if(area[y2][x2]=='#')
                            {   
                                int area2 = 1;
                                for(int l2=1;;l2++)
                                {
                                    area2+=4;
                                    if(x2-l2 < 0 || x2+l2>=m || y2-l2 < 0 || y2+l2>=n) break;
                                    if(area[y2][x2+l2]!='#' || area[y2][x2-l2]!='#' || area[y2+l2][x2]!='#' || area[y2-l2][x2]!='#') break;
                                    ans = max((4*l+1)*(4*l2+1),ans);
                                }
                            }

                        }
                    }
                    // 십자가 1 원상복구
                    for(int l=0;;l++)
                    {
                        if(x1-l < 0 || x1+l>=m || y1-l < 0 || y1+l >=n) break;
                        if(area[y1][x1+l]!='*' || area[y1+l][x1]!='*' || area[y1][x1-l]!='*' || area[y1-l][x1]!='*') break;
                        
                        area[y1][x1+l]='#'; area[y1][x1-l]='#'; area[y1+l][x1]='#'; area[y1-l][x1]='#';
                    }    
                }
            }
        }
    }

    cout << ans;
    


    return 0;
}