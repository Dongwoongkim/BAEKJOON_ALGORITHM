#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
 
struct Wall {
public:
    // 0->남, 1->동, 2->북, 3->서
    bool dir[4];
    Wall(){
        memset(dir, false, sizeof(dir));
    }
    Wall(string binary){
        memset(dir, false, sizeof(dir));
        for(int i = 0; i < 4; i++){
            if(binary[i] == '1')
                dir[i] = true;
        }
    }
};
 
int n,m;
int map[50][50];
Wall wall[50][50];
bool visited[50][50];
 
int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};
 
int bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = true;
    int cnt = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(wall[r][c].dir[i]) continue;
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if(visited[nr][nc]) continue;
            q.push({nr,nc});
            visited[nr][nc] = true;
            cnt++;
        }
    }
    return cnt;
}
 
void answerQuestion(){
    int roomNum = 0, roomSize = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                //소문제 1
                roomNum++;
                int size = bfs(i,j);
                //소문제 2
                if(roomSize < size)
                    roomSize = size;
            }
        }
    }
    cout << roomNum << endl;
    cout << roomSize << endl;
    //소문제 3
    int maxRoomSize = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                //외각 벽은 허물지 않는다
                if(i == 0 && k == 2) continue;
                if(i == m-1 && k == 0) continue;
                if(j == 0 && k == 3) continue;
                if(j == n-1 && k == 1) continue;
                //만약 허물 벽이 없다면 무시
                if(!wall[i][j].dir[k]) continue;
                
                memset(visited, false, sizeof(visited));
                wall[i][j].dir[k] = false;
                int size = bfs(i,j);
                if(size > maxRoomSize) maxRoomSize = size;
                wall[i][j].dir[k] = true;
            }
        }
    }
    cout << maxRoomSize << endl;
}
 
string changeBinary(int num){
    string binary = "";
    while(num > 0){
        if(num % 2 == 1){
            binary = '1'+ binary;
        }else{
            binary = '0' + binary;
        }
        num /= 2;
    }
    while(binary.size() < 4){
        binary =  '0' + binary;
    }
    return binary;
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            string binary = changeBinary(num);
            Wall w(binary);
            wall[i][j] = w;
        }
    }
    answerQuestion();
    return 0;
}