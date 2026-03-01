#include <stdio.h>
#include <string.h>
int main(){
    char m[42],n[100000];
    int w[41]={0},ml,nl;
    gets(m);
    gets(n);
    ml=strlen(m);
    nl=strlen(n);
    for(int i=0;i<ml;i++){
	if(m[i]>='A'&&m[i]<='Z'){
	    w[m[i]-'A']=1;
	}
	if(m[i]>='0'&&m[i]<='9'){
	    w[m[i]-'0'+26]=1;
	}
	else{
	    switch(m[i]){
		case '_':  w[36]=1;  break;
		case ',':  w[37]=1;  break;
		case '.':  w[38]=1;  break;
		case '-':  w[39]=1;  break;
		case '+':  w[40]=1;  break;
	    }
	}
    }
    for(int i=0;i<nl;i++){
	if(n[i]>='a'&&n[i]<='z'){
	    if(!w[n[i]-'a'])
		printf("%c",n[i]);
	}
	else if(n[i]>='A'&&n[i]<='Z'){
	    if(!w[n[i]-'A']&&!w[40])
		printf("%c",n[i]);
	}
	else if(n[i]>='0'&&n[i]<='9'){
	    if(!w[n[i]-'0'+26])
		printf("%c",n[i]);
	}
	else{
	    switch(n[i]){
		case '_':  if(!w[36])  printf("%c",n[i]); break;
		case ',':  if(!w[37])  printf("%c",n[i]); break;
		case '.':  if(!w[38])  printf("%c",n[i]); break;
		case '-':  if(!w[39])  printf("%c",n[i]); break;
		case '+':  if(!w[40])  printf("%c",n[i]); break;
	    }
	}
    }
    printf("\n");
    return 0;
}
