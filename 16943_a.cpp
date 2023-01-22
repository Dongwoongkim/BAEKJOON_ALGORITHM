#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;
string a;
int b;
string na;
bool check[10];

int answer = -1;
void ans(int index)
{   
    if(index==a.length())
    {
        int c = stoi(na);
        cout << c << endl;
        if(c<b && na[0] !='0')
        {
            answer = max(c,answer);
        }

        return;
    }

    else
    {
        for(int i=0;i<a.length();i++)
        {
            if(check[i]==false)
            {
                check[i] = true;
                na[index] = a[i];
                ans(index+1);
                check[i] = false;
            }
        }
    }

}

int main()
{
    FASTio;
    cin >> a;
    cin >> b;
    ans(0);

    cout << answer << endl;

    return 0;
}