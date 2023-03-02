#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,m;
vector<string> v(50);
int cnt = 64;

string bw[8]=
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

string wb[8]=
{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

int WB(int i,int j)
{   
    int cnt = 0;
    int s1=0;
    int s2=0;

    for(int y=i;y<i+8;y++)
    {   
        s2=0;
        for(int x=j;x<j+8;x++)
        {   
            if(v[y][x]!=wb[s1][s2])
            {
                cnt++;
            }
            s2++;
        }
        s1++;
    }

    return cnt;
}

int BW(int i,int j)
{
    int cnt = 0;
    int s1=0;
    int s2=0;
    for(int y=i;y<i+8;y++)
    {
        s2=0;
        for(int x=j;x<j+8;x++)
        {   
            if(v[y][x]!=bw[s1][s2])
            {
                cnt++;
            }
            s2++;
        }
        s1++;
    }
    return cnt;
}
int main()
{
    FASTio;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
   
    for(int i=0;i<=n-8;i++)
    {
        for(int j=0;j<=m-8;j++)
        {
            cnt = min((min(WB(i,j),BW(i,j))),cnt);
        }
    }

    cout << cnt;
    

    return 0;
}