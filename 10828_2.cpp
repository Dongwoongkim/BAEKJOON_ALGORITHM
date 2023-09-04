#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

stack <int> st;
int n;
int num;
string s;

int main()
{
    FASTio;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s;
        if(s == "push"){
            cin >> num;
            st.push(num);
        } else if(s == "top"){
            if(st.empty()){
                cout << -1 << endl;
            } else {
                cout << st.top() << endl;
            }
        } else if (s == "size"){
            cout << st.size() << endl;
        } else if(s == "empty"){
            if(st.empty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if(s == "pop"){
            if(st.empty()){
                cout << -1 << endl;
            } else {
                cout << st.top() << endl;
                st.pop();
            }
        }
    }


    return 0;
}