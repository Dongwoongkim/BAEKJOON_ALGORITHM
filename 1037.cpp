#include<iostream>
#include <vector>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int n;
int sum=1;
int num[51];

int main(){
	int num=0;
	vector<int> v;
	int select = 0;
	cin >> select;
	while (select--)
	{
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(),v.end());
	
	cout << v[0] * v.back() << endl;

	return 0;
}