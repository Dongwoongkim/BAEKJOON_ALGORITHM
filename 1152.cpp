#include <stdio.h>
#include <string.h>
int count;
int slen;
char s[1000001];

int main(){
	
	scanf("%[^\n]s",s);
	
	slen = strlen(s);

for(int i=1;i<slen;i++){
	
	if(s[i]==' '){
		count++;
	}
}
if(s[slen-1]==' '){
	count-=1;
}

printf("%d",count+1);
	
	return 0;
}