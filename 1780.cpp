#include <iostream>
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
int n;
int v[2200][2200];
int cnt_m1,cnt_0,cnt_1;
bool check(int size,int y,int x)
{
	int stdnum = v[y][x];

	for(int i=y;i<y+size;i++)
	{
		for(int j=x;j<x+size;j++)
		{
			if(stdnum!=v[i][j]) return false;
		}
	}


return true;

}

void d_q(int size,int y,int x)
{

	if(check(size,y,x)==true)
	{
		if(v[y][x]==-1) cnt_m1 ++;
		if(v[y][x]==0) cnt_0 ++;
		if(v[y][x]==1) cnt_1++;

	}


	if(check(size,y,x)==false)
	{
		d_q(size/3,y,x); // 1
		d_q(size/3,y,x+(size/3)); // 2
		d_q(size/3,y,x+(size/3)*2); //3 
		d_q(size/3,y+size/3,x); // 4
		d_q(size/3,y+(size/3),x+(size/3)); // 5
		d_q(size/3,y+(size/3),x+(size/3)*2); // 6
		d_q(size/3,y+(size/3)*2,x); // 7
		d_q(size/3,y+(size/3)*2,x+size/3); // 8
		d_q(size/3,y+(size/3)*2,x+(size/3)*2); // 9
	}
}

int main()
{
	FASTio;
	cin >> n;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> v[i][j];

	d_q(n,0,0);

	cout << cnt_m1 << endl << cnt_0 << endl << cnt_1;
		

	

	return 0;
}