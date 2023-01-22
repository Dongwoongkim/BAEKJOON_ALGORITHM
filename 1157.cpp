#include <stdio.h>
#include <string.h>
char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char s[1000001];
int count[26];
int t,max,v;
int main(){
	scanf("%s",s);
	int slen = strlen(s);
	for(int i=0;i<slen;i++){
		if(s[i]>=97){
			s[i]-=32;
		}
		
}

	for(int i=0;i<slen;i++){
		for(int j=0;j<26;j++)
		{
		if(s[i]==alphabet[j]){
			count[j]++;}}}
	
	
	max = 0;
	
	for(int a=0;a<26;a++){
	
		if(max<count[a]){
			
			max=count[a];
			
			t = a;
		
			}}
	
	for(int a=0;a<26;a++){
		
		if(count[a]==max){
			v++;
		}
	}
	
	if(v>=2){
		printf("?\n");
	}
	else{printf("%c",alphabet[t]);
}

		
		

return 0;}