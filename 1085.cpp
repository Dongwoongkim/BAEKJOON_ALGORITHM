#include <stdio.h>
#include <math.h>

int x,y,w,h;
int min;
int main()
{	// x,y,w,h 스캔받 
	scanf("%d %d %d %d",&x,&y,&w,&h);
	
	int xyup,xydown,xyright,xyleft;
	
	xyup = h-y;
	xydown = y;
	xyleft = x;
	xyright = w-x;
	
	min = xyup;
	
	if(xydown<min){
		min =xydown;
	}
	if(xyleft<min){
		min =xyleft;
	}
	if(xyright<min){
		min =xyright;
	}
	
	printf("%d",min);
	
	return 0;
}
