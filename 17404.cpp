#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;


int v[1001][3];

int ans = 1000*1000;
int main()
{
    FASTio;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> v[i][j];
        }
    }


    for(int start=0;start<3;start++)
    {
        vector<vector<int>> d(1001,vector<int>(3,0));

        // 1열 세팅 
        for(int i=0;i<3;i++)
        {   
            d[0][i] = v[0][i];
        }

        // 2열 초기화
        for(int i=0;i<3;i++)
        {
            if(i==start) d[1][i] = 1000*1000; 
            else
            {
                d[1][i] = d[0][start] + v[1][i];
            }
        }

        // 3열부터 채우기
        for(int i=2;i<n;i++)
        {
            d[i][0] = min(d[i-1][1],d[i-1][2]) + v[i][0];
            d[i][1] = min(d[i-1][0],d[i-1][2]) + v[i][1];
            d[i][2] = min(d[i-1][0],d[i-1][1]) + v[i][2];
        }

        // 시작 색깔과 마지막 색깔이 같으면 pass, 다르면 누적해서 검사
        for(int end=0;end<3;end++)
        {
            if(start == end) continue;
            ans = min(ans, d[n-1][end]);
        }
    }

    cout << ans;

    return 0;
}