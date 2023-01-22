#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char st[30001],lc[30001];

int lenst =0;
int lenlc=0;

int main(){
fgets(st,30002,stdin);  

scanf("%s",lc); 

lenst=strlen(st)-1; 
lenlc=strlen(lc);

for(int i=0;strlen(lc)<strlen(st)-1;i++){
	lc[i+lenlc] = lc[i];}

for(int i=0;i<lenst;i++){
	if(st[i]==' '){
		lc[i]=' ';
	}
}


int s[30001],l[30001];

for(int i=0;i<lenst;i++){
	s[i]=st[i];
	l[i]=lc[i];
}

for(int i=0;i<lenst;i++){

	
	
	if(s[i]==l[i])	{
	
	if(l[i]==32){
		printf(" ");
	}
	
	else {printf("%c",26+96);}}     
	
	else {
	if(s[i]>l[i]){ 
		printf("%c",s[i]-l[i]+96);
	}
	
	else if(s[i]<l[i]){
		printf("%c",96+26+s[i]-l[i]);
	}
	
		}}

return 0;
}