#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;
int a,b,c;
vector <int> ans;
int water[4];
bool check[201];

bool visited[201][201];

void bfs(int Asize, int Bsize, int Csize)
{
    queue <pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(0,0),c));

    while(!q.empty())
    {
        int a,b,c;
        a = q.front().first.first;
        b = q.front().first.second;
        c = q.front().second;

        q.pop();

        if(a==0) check[c]=true;
        

        if(visited[a][b]==false)
        {   
            visited[a][b]=true;

            // A->B
            if(a+b>Bsize)
            {   
                q.push(make_pair(make_pair(a+b-Bsize,Bsize),c));
            }
            else if(a+b<=Bsize)
            {   
                q.push(make_pair(make_pair(0,a+b),c));
            }

            // A->C
            if(a+c>Csize)
            {
                q.push(make_pair(make_pair(a+c-Csize,b),Csize));
            }
            else if(a+c<=Csize)
            {
                q.push(make_pair(make_pair(0,b),a+c));
            }

            // B->A

            if(b+a>Asize)
            {
                q.push(make_pair(make_pair(Asize,a+b-Asize),c));
            }
            else if(b+a<=Asize)
            {
                q.push(make_pair(make_pair(a+b,0),c));
            }
            // B->C
            if(b+c>Csize)
            {
                q.push(make_pair(make_pair(a,b+c-Csize),Csize));
            }
            else if(b+c<=Csize)
            {
                q.push(make_pair(make_pair(a,0),b+c));
            }

            // C->A
            if(c+a>Asize)
            {
                q.push(make_pair(make_pair(Asize,b),a+c-Asize));
            }
            else if(c+a<=Asize)
            {
                q.push(make_pair(make_pair(a+c,b),0));

            }

            // C->B
            if(c+b>Bsize)
            {
                q.push(make_pair(make_pair(a,Bsize),b+c-Bsize));
            } 
            else if(c+b<=Bsize)
            {
                q.push(make_pair(make_pair(a,c+b),0));
            }

        }

    }
    

}
int main()
{
    FASTio;
    cin >> a >> b >> c;
    bfs(a,b,c);
    
    for(int i=0;i<=c;i++)
    {
        if(check[i]==true) cout << i << ' ';
    }
    
    return 0;
}