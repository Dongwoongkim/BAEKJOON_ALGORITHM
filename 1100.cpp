#include <stdio.h>

char chess[8][8];
int count=0;

int main(){
	

	
	for(int i=0;i<8;i++)
	{	
		for(int j=0;j<8;j++)
		{	
			scanf("%c ",&chess[i][j]);
		}
	}	
	
	for(int i=0;i<8;i++)
	{
		
		for(int j=0;j<8;j++)
		{	
			if(i%2==0 && j%2==0)
			{
				if(chess[i][j]== 'F' )
				{
					count++;
				}
			}
			
			if(i%2!=0 && j%2!=0)
			{
				if(chess[i][j]=='F')
				{
					count++;
				}
			}
		}
	}
	
	
	printf("%d",count);
	
	return 0;
}