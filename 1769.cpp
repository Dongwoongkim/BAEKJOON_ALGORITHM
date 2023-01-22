#include<iostream>
#include <vector>
#include <string>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <string>
using namespace std;

	int sum;
	int cnt=0; 

string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
} // int를 string으로 바꾸는 함수
 

void ans(string s)
{	
	
		
	// 만약에 최초로 쓴 정수가 한자리 수 인 경우
	// 3으로나누어떨어지면 0 endl yes , else  0 endl no 
	
	if(s.size()==1){
		if((s[0]-'0')%3==0)	{
			cout << 0 << endl << "YES";
		}
		if((s[0]-'0')%3!=0){
			cout << 0 << endl << "NO";
		}
	}

	
	
	// 만약 최초로 쓴 숫자가 두자리수 이상인경우 

	
	else{
	do
	{	
		sum=0;
		
		for(size_t i=0;i<s.size();i++)
		{sum+= s[i]-'0';} // 문자열들의 합을 정수로 바꿔 sum에 저장   
		
		s = IntToString(sum); // sum을 문자열로 바꿔서 s에 저장. 
		 
	
		cnt++; // 정수 재정립했으니 cnt 증가 
		
		if(s.length()==1 && sum%3==0 && sum!=0){
		
			cout << cnt << endl << "YES";
			break;
		}	// 한자리숫자가 되고 3으로나눈나머지가 0인경우 
		
		else if(s.length()==1 &&sum%3!=0){
		
			cout << cnt << endl << "NO";
			break;
		}
		// 한자리숫자가되고 3으로나눈나머지가 0이아닌경우 
		

	}while(s.size()>1);
	
}}
int main(){
	string x;
	cin >> x;
	
	ans(x);
	
	return 0;}