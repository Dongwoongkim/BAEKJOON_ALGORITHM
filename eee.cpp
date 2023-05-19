#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v(100, vector<int>());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0;j<v[i].size();j++){
            cout << v[i].at(j) << ' ';
        }
        cout << endl;
    }
    return 0;
}