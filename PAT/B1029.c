#include <stdio.h>
#include <string.h>
int main(){
    int ml,nl;
    char m[81],n[81];
    int s[37]={0};
    gets(n);
    gets(m);
    ml=strlen(m);
    nl=strlen(n);
    for(int i=0;i<ml;i++){
	if(m[i]!='_'){
	    if(m[i]>='a'&&m[i]<='z')
		s[m[i]-'a']=1;
	    else if(m[i]>='0'&&m[i]<='9')
		s[m[i]-'0'+26]=1;
	    else
		s[m[i]-'A']=1;
	}
	else  s[36]=1;
    }
    for(int i=0;i<nl;i++){
	if(n[i]!='_'){
	    if(n[i]>='a'&&n[i]<='z')
		{if(!s[n[i]-'a'])  {printf("%c",n[i]-'a'+'A');  s[n[i]-'a']=1;}}
	    else if(n[i]>='0'&&n[i]<='9')
		{if(!s[n[i]-'0'+26])  {printf("%c",n[i]);  s[n[i]-'0'+26]=1;}}
	    else
		{if(!s[n[i]-'A'])  {printf("%c",n[i]);  s[n[i]-'A']=1;}}
	}
	else  {if(!s[36])  {printf("_");  s[36]=1;}}
    }
    printf("\n");
    return 0;
}
