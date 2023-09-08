#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n;
string s;

string answer(bool ans){
    if(ans==true){
        return "YES";
    } else {
        return "NO";
    }
}

int main()
{
    FASTio;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int cnt = 0;
        bool ans = true;
        cin >> s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('){
                cnt ++;
            } else if(s[i] == ')')
            {
                cnt --;
            }

            if (cnt < 0)
            {
                ans = false;
                break;
            }
        }

        if(cnt == 0){
            ans = true;
        } else {
            ans = false;
        }
        
        cout << answer(ans) << endl;

    }


    return 0;
}