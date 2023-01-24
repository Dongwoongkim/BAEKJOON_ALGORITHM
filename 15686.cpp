#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
int ans = -1;
vector<vector<int>> area(51,vector<int>(51,0));
vector<pair<int,int>> chicken;
vector<pair<int,int>> home;


int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> area[i][j];
            if(area[i][j]==2)
            {
                chicken.push_back(make_pair(i,j));
            }
            else if(area[i][j]==1)
            {
                home.push_back(make_pair(i,j));
            }
        }
    }

    vector<int> d(chicken.size());

    for(int i=0;i<m;i++)
    {
        d[i] = 1;
    }

    for(int i=m;i<chicken.size();i++)
    {
        d[i] = 0;
    }

    sort(d.begin(),d.end());

    do
    {
        int sum = 0;
        for(auto &p : home)
        {
            vector<int> dists;
            
            // 
            for(int i=0;i<chicken.size();i++)
            {
                if(d[i]==0) continue;
                
                // 선택한 치킨집에 대해서만 거리계산
                auto &s = chicken[i];
                int d1 = abs(p.first - s.first);
                int d2 = abs(p.second - s.second);
                int dist = d1+d2;

                // 계산한 거리 dists에 푸쉬
                dists.push_back(dist);
            }


            // 계산한 거리중 최소값을 sum에 더해줌 -> 도시의 치킨 거리
            sum += *min_element(dists.begin(),dists.end());
        }

        if(ans==-1 || sum<ans)
        {   ans = sum;
        }

    } while(next_permutation(d.begin(),d.end()));
    

    cout << ans;

    return 0;
}