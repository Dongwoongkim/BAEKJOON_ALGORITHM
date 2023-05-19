#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;


// 부모 노드 찾는 함수 
int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b){
    a = getParent(parent,a);
    b = getParent(parent,b);
    if (a<b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는 지 확인
int findParent(int parent[],int a,int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return 1;
    else
    {
        return 0;
    }
}

int main()
{
    FASTio;
    int parent[11];
    for(int i=1;i<=10;i++){
        parent[i] = i;
    }

    unionParent(parent,1,2);
    unionParent(parent,2,3);
    unionParent(parent,3,4);
    unionParent(parent,5,6);
    unionParent(parent,6,7);
    unionParent(parent,7,8);

    cout << "1 connect? 5 " << findParent(parent,1,5) << endl;
    return 0;
}