#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int cnt=0;
int n,r,c;

void dq(int size,int y, int x)
{   
    if(y==r && x==c)
    {
        cout << cnt;
        return;
    }   
    
    if(r < y+size && c < x+size && r>=y && c>=x)
    {
        dq(size/2,y,x);
        dq(size/2,y,x+(size/2));
        dq(size/2,y+(size/2),x);
        dq(size/2,y+(size/2),x+(size/2));
    }
    else
    {
        cnt += size*size;
    }
}

int main()
{
    FASTio;
    cin >> n >> r >> c;

    int k = 1;
    for(int i=1;i<=n;i++)
    {
        k*=2;
    }

    dq(k,0,0);
    return 0;
}