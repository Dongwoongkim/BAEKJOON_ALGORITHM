#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

map<string,pair<char,string>> m;

int main()
{
    FASTio;
    m.insert({"black",make_pair('0',"")});
    m.insert({"brown",make_pair('1',"0")});
    m.insert({"red",make_pair('2',"00")});
    m.insert({"orange",make_pair('3',"000")});
    m.insert({"yellow",make_pair('4',"0000")});
    m.insert({"green",make_pair('5',"00000")});
    m.insert({"blue",make_pair('6',"000000")});
    m.insert({"violet",make_pair('7',"0000000")});
    m.insert({"grey",make_pair('8',"00000000")});
    m.insert({"white",make_pair('9',"000000000")});

    string ans;
    string a,b,s;


    cin >> a;
    if(a!="black")
        ans += m[a].first;

    cin >> b;
    ans += m[b].first;

    cin >> s;

    if(!(a=="black" && b=="black"))  
        ans += m[s].second;

    cout << ans << endl;
    return 0;
}