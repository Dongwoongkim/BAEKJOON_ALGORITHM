#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n,m;
int a[4001][4001];
vector<int> d(4001);
int f1,f2;
int ans = -1;

int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        cin >> f1 >> f2;   
        a[f1][f2] = 1;

        // 친구관계 오름차순 입력이라는 조건이 없으므로 내림차순입력인 경우
        a[f2][f1] = 1;

        d[f1] +=1; // f1의 친구수 1증가
        d[f2] +=1; // f2의 친구수 1증가

    }

    // A,B가 친구일 경우에만 C를 구한다 -> O(n*n + mn)
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            // i와 j가 친구라면
            if(a[i][j]==1)
            {
                for(int k=j+1;k<=n;k++)
                { 
                    // i와 k가 친구이고 j와 k도 친구인 즉 세친구가 모두 서로 친구인경우    
                    if(a[i][k]==1 && a[j][k]==1)    
                    {   
                        int sum = d[i] + d[k] + d[j] - 6;
                        if(ans==-1 || ans>sum)
                            ans = sum;
                    } 
                }
            }
        }
    }   



    // // O(n*n*n) -> 시간초과
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=i+1;j<=n;j++)
    //     {
    //         for(int k=j+1;k<=n;k++)
    //         { 
    //             if(a[i][k]==1 && a[j][k]==1 && a[i][j]==1)    
    //             {   
    //                 int sum = d[i] + d[k] + d[j] - 6;
    //                 if(ans==-1 || ans>sum)
    //                     ans = sum;
    //             } 
    //         }
    //     }
    // }   


    cout << ans;


    return 0;
}