#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;
int ans = -9999999;
string str;

vector<pair<int,char>> cer;

void dfs(int index, int cur)
{   
    int tmp = cer[cur].first;
    // 길이 n에 도달한 경우 max ans 리턴
    if(index>=n)
    {   
        ans = max(ans,cur);
        return;
    }

    // 괄호 O
    if(index+2<n)
    {   
        int tmp = 0;
        // 괄호 식  
        if(cer[index+1].second=='-')
        {
            tmp = cer[index].first - cer[index+2].first;
        }
        else if(cer[index+1].second=='+')
        {
            tmp = cer[index].first + cer[index+2].first;
        }
        else if(cer[index+1].second=='*')
        {
            tmp = cer[index].first * cer[index+2].first;
        }


        // 이전 + 괄호 

        if(cer[index-1].second == '-')
        {
            dfs(index+4,cur-tmp);
        }

        if(index==0 || cer[index-1].second == '+')
        {
            dfs(index+4,cur+tmp);
        }

        if(cer[index-1].second == '*')
        {
            dfs(index+4,cur*tmp);
        }
    }    


    // 괄호 X // 이전 + 다음

    if(cer[index-1].second == '-')
    {
        dfs(index+2,cur-cer[index].first);
    }

    if(index == 0 || cer[index-1].second == '+')
    {
        dfs(index+2,cur+cer[index].first);
    }

    if(cer[index-1].second == '*')
    {
        dfs(index+2,cur*cer[index].first);
    }
    
}
int main()
{
    FASTio;
    cin >> n;
    cin >> str;

    for(int i=0;i<n;i++)
    {
        // 숫자 case
        if(i%2==0)
        {
            cer.push_back(make_pair(str[i]-'0','+'));
        }

        // 연산자 case
        else if(i%2==1)
        {
            if(str[i]=='+')
            {
                cer.push_back(make_pair(0,'+'));
            }

            else if(str[i]=='-')
            {
                cer.push_back(make_pair(0,'-'));
            }

            else if(str[i]=='*')
            {
                cer.push_back(make_pair(0,'*'));
            }
        }
    }
    dfs(0,0);
    cout << ans << endl;
 
    return 0;
}