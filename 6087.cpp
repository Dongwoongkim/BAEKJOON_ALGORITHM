#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int w,h;
vector<vector<char>> area(101,vector<char>(101));
vector<vector<int>> vNum(101,vector<int>(101));
vector<pair<int,int>> v;
int s=-1;
int e=-1;

int main()
{
    FASTio;
    cin >> w >> h;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> area[i][j];
            if(area[i][j]=='C')
            {
                if(s==-1)
                {
                    s = v.size();
                }
                else{
                    e = v.size();
                }
                v.push_back(make_pair(i,j));
                num[i][j] = v.size();
            }

            else if(area[i][j]=='.')
            {
                v.push_back(make_pair(i,j));
                num[i][j] = v.size()-1;
            }
        }
    }

    return 0;
}