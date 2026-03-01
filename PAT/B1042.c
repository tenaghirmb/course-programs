#include <stdio.h>
#include <string.h>
int main(){
    int nl,f[26]={0},max=0;
    char n[1001],c;
    gets(n);
    nl=strlen(n);
    for(int i=0;i<nl;i++){
	if(n[i]>='a'&&n[i]<='z'){
	    f[n[i]-'a']++;
	}
	else if(n[i]>='A'&&n[i]<='Z'){
	    f[n[i]-'A']++;
	}
    }
    for(int i=0;i<26;i++){
	if(f[i]>max){
	    max=f[i];
	    c='a'+i;
	}
    }
    printf("%c %d\n",c,max);
    return 0;
}
