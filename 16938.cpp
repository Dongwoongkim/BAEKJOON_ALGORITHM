#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

// l<=난이도 합<=r
// max-min>=x
// 문제고르는 경우의 수 = 2^n개 
// 최대문제수 15 => 2^15 = 32768

int n,l,r,x;
int cntq = 0;

int arr[16];
bool choose[16];

// 문제를 전부 다 살펴보기
int ans(int index)
{   
    // 전체 문제를 다 
    if(index == n)
    {   
        int cnt = 0;
        int sum = 0;
        int hard = -1;
        int easy = 100000001;

        for(int i=0;i<n;i++)
        {   

            // 선택한 문제에 대해서만 
            if(choose[i]==true)
            {
            sum += arr[i];
            cnt++;
            hard = max(arr[i],hard);
            easy = min(arr[i],easy);
            }
        }

        // 조건만족시 return 1
        if(cnt>=2 && l <= sum && r>= sum && hard-easy >= x)
        {
            return 1;
        }

        else 
        {
            return 0;
        }
    }

    // 현재 index 문제를 고르는 경우
    choose[index] = true;
    int cnt1 = ans(index+1);
    choose[index] = false;

    // 현재 index 문제를 고르지 않는 경우
    int cnt2 = ans(index+1);

    return cnt1+cnt2;

}




int main()
{
    FASTio;
    
    cin >> n >> l >> r >> x;
    
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout << ans(0);

    return 0;
}