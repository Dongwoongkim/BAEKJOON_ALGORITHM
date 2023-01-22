#include<iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <vector>
#include <utility>
using namespace std;

vector <pair<int,int> > v; // 숫자들을 입력받아서 짝을지어 
vector <bool> check; 

int a[21],b[21]; // 숫자입력해서 저장한뒤 짝을지을때 사용할 입력받을 배열변수 선언
int n; // 몇개의 짝을 만들지

int pos; // 
int m; // 몇개 고를지 선택하는 변수
int sum; // 체력값의합
int sumb=0; // 기쁨값의합
int mx=0; // 최댓값

void make_pair(int n){
		
	for(int i=0;i<n;i++){
		cin >> a[i]; // 체력 입력 0번째부터 n-1번째 사람까지
	}
	
	for(int i=0;i<n;i++){
		cin >> b[i]; // 기쁨 입력 : 0번쨰부터 n-1번째 사람가지
	}
	
	for(int i=0;i<n;i++){
		
		v.push_back(pair<int,int>(a[i],b[i])); // a[0]-b[0], a[1]-b[1] .. a[n-1]-b[n-1] 짝짓기
	}


}

void answer(int n,int by,vector <bool> &check,int pos,int m,vector <int> &hp,vector <int> &happy){

	
	if(pos == m){
	
		for(size_t j=0;j<m;j++){
			sum+= hp[j]; // 체력값의 합을구해
		}
		
		if(sum<100){ // 체력값의 합인 sum이 100이하인경우
			
			for(size_t k=0;k<m;k++){
				
				sumb+= happy[k]; // 기쁨값의 합을구해 sumb = 기쁨값의 합
			}
			
			if(sumb>=mx){ // 기쁨값의 최댓값구해
				mx= sumb;
			}
		}

		
		sum =0; //  
		sumb=0; // 한번 돌렸으면 체력값 기쁨값 초기화시켜줘 
		
		return;
	
	
	
	}
	
	
		
		int i=0;
		

		for(i=by;i<n;i++){
			if(check[i]==false){
			    hp[pos]=v[i].first;  
				happy[pos]=v[i].second;
				check[i]=true;
				answer(n,i,check,pos+1,m,hp,happy);
				check[i]=false;
				
			}
		
			} // 1개고르는경우부터시작 (중복선택 x)
		
}

int main(){
	
	
	cin >> n;
	vector <int> hp(n,0); // 체력값
	vector <int> happy(n,0); // 기쁨값
	
	vector <bool> check(n+1,false); // 
	make_pair(n); // n개만큼 체력값과 기쁨값을짝을지어 
	
	for(int m=1;m<=n;m++){
	answer(n,0,check,0,m,hp,happy);} // n개중에서 1개 고르는경우부터시작해서 2개고르는경우 .. n개 고르는경우 (중복 x)
                                   // 모든경우의 체력의 합을 구해서 합이 100이하일때 기쁨의합의 최대를구함
	
	cout << mx; // 최댓값 출력
	
}