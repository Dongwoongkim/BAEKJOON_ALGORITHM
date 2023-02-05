#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int main()
{
    FASTio;

    int n;
    cin >> n;

    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> num[i];
        sum+=num[i];

    }

        Arrays.sort(num);
        int[] freq = new int[8001];

        for(int i=0;i<n;i++)
        {
            freq[num[i]+4000]++;
        }

        int m=0;

        for(int i=8000;i>=0;i--)
        {
            if(freq[i]>=freq[m])
            {
                m = i;
            }
        }

        for(int i=m+1;i<8001;i++)
        {
            if(freq[m]==freq[i])
            {
                m = i;
                break;
            }
        }

        double first = (double)(sum)/n;
        if(0>first && first>-0.5)
        {
            System.out.println(0);
        }
        else
        {
            System.out.printf("%.0f\n",(double)(sum)/n);
        }
        System.out.printf("%d\n",num[n/2]);
        System.out.println(m-4000);
        System.out.printf("%d\n",num[n-1]-num[0]);
    return 0;
}

