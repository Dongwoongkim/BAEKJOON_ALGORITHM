#include <iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <string.h>
#include <vector>
#include <utility>
using namespace std;


bool comp(pair <string,int> p1,pair <string,int> p2){
	
	if(p1.second==p2.second){
		
		return p1.first < p2.first; // 빈도수같으면 사전순  
	}
	else{
		return p1.second < p2.second; // 다르면 짧은순 
	}}


// 정렬을 어떻게 할것인가 ? 

int n;
int a; 

vector <pair<string,int> > l;

// 벡터페어 l선언 여기안에는 <문자열,문자열길이>
 
int main(){
	FASTio;
	cin >> n;
	// 단어갯수
	 
	for(int i=0;i<n;i++){
		string k;
		cin >> k;
		a = k.size();
		l.push_back(pair<string,int>(k,a));
	}
	
	// 입력받음 -> l벡터페어에 문자열,문자열길이 저장
	 
	
	sort(l.begin(),l.end(),comp);
	
	// 정렬하기, 어떻게? 위에서정의한 comp 함수 방식으로 
	 
	l.erase( unique (l.begin(), l.end() ) ,l.end());
 	
 	
 	// 중복된거 지워주자 지우는방법은 l.erase( unique(l.begin,l.end()),  l.end() );
	  
	for(int i=0;i<l.size();i++){
		cout << l[i].first << endl;
	}
	
	// 완성본 출력   
	

return 0; 
}
