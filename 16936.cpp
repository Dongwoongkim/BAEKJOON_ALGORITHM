#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int n;
long long num;

// arr의 원소들을 소인수분해 했을 때 3의 개수가 제일 많은 순대로 정렬 


int main()
{
    FASTio;
    cin >> n;
    vector <pair<int,long long> > v(n);
    for(int i=0;i<n;i++)
    {
        cin >> num;
        v[i].second = num;
        while(num%3==0)
        {
            num/=3;
            v[i].first++;
        }
        // sort 할때 greater<>로 하면 first 내림차순 정렬 후 second도 내림차순으로 되니 (곱2니까 오름차순 이어야 함) 그냥 음수로 변환했음
        v[i].first = -v[i].first;
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++)
    {
        cout << v[i].second << ' ';
    }

    return 0;
}