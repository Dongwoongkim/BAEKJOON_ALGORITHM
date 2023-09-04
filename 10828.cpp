#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

int n,num;
int p = -1;
string s;
vector <int> v(10000,0);

int main()
{
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s;
        if(s == "push"){
            p++;
            cin >> num;
            v[p] = num;
        } else if(s == "top"){
            if(p == -1){
                cout << -1 << endl;
            } else {
                cout << v[p] << endl;
            }
        } else if (s == "size"){
            cout << p+1 << endl;
        } else if(s == "empty"){
            if(p==-1) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if(s == "pop"){
            if(p==-1){
                cout << -1 << endl;
            } else {
                cout << v[p] << endl;
                p--;
            }
        }
    }

    return 0;
}