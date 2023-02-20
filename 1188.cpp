#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;
int n,m;

int gcd(int n,int m)
{   
    if(n%m==0)
        return m;
    return gcd(m,n%m);
}
int main()
{
    FASTio;
    cin >> n >> m;

    cout << m - gcd(n,m);
}