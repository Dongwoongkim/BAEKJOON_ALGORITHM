#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 
using namespace std;

// test

char arr[101][101];
bool check[101][101];
int n,m;
vector <pair<pair<int,int>,int>> v;

int main()
{
    FASTio;
    cin >> n >> m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]=='*')
            {   
                int l = 0;

                for(int size=1;;size++)
                {
                    if(size+j >= 1 && size+i >=1 && size+j <=m && size+i <=n)
                    {   
                        if(arr[i][j+size] == '*' && arr[i+size][j] == '*'
                        && arr[i][j-size]=='*' && arr[i-size][j] == '*')
                        {
                            l = size; 
                        }

                        else
                        {  
                            break;
                        }
                    }
                    else break;
                }

                if(l>0)
                {
                    v.push_back(make_pair(make_pair(i,j),l));

                    check[i][j] = true;
                    for(int k=1;k<=l;k++)
                    {
                        check[i+k][j] = true;
                        check[i-k][j] = true;
                        check[i][j+k] = true;
                        check[i][j-k] = true;
                    }   
                }

            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]=='*' && check[i][j]==false)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << v.size() << endl;
    for(int i=0;i<v.size();i++)
    {
        cout << v[i].first.first << ' ' << v[i].first.second << ' ';
        cout << v[i].second << endl;
    }
    return 0;
}