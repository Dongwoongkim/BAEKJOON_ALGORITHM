#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

map <string, int> monster;
map <int, string> monster2;
int main(void){
   FASTio;
   int n,m;
   string key;
   string question;
   cin >> n >>m;
   
   for(int i=1;i<=n;i++){
      cin >> key;
      monster.insert({key, i});
      monster2.insert({i, key});
      // key는 포켓몬이름, i는 첫번째부터 ~  
   }
   for(int i=0;i<m;i++){
      cin >> question;
      if(question[0]<='9' && question[0] >= '0'){
         cout<<monster2[stoi(question)]<<'\n';
      }
      else
      cout<<monster[question]<<'\n';
   } 
}