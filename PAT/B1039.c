#include <stdio.h>
#include <string.h>
int main(){
    char m[1001],n[1001];
    int w[62]={0},a=0,ml,nl;
    gets(m);
    gets(n);
    ml=strlen(m);
    nl=strlen(n);
    for(int i=0;i<ml;i++){
	if(m[i]>='a'&&m[i]<='z'){
	    w[m[i]-'a']++;
	}
	else if(m[i]>='A'&&m[i]<='Z'){
	    w[m[i]-'A'+26]++;
	}
	else{
	    w[m[i]-'0'+52]++;
	}
    }
    for(int i=0;i<nl;i++){
	if(n[i]>='a'&&n[i]<='z'){
	    if(w[n[i]-'a']){
		a++;
		w[n[i]-'a']--;
	    }
	}
	else if(n[i]>='A'&&n[i]<='Z'){
	    if(w[n[i]-'A'+26]){
		a++;
		w[n[i]-'A'+26]--;
	    }
	}
	else{
	    if(w[n[i]-'0'+52]){
		a++;
		w[n[i]-'0'+52]--;
	    }
	}
    }
    if(a==nl)
	printf("Yes %d\n",ml-nl);
    else
	printf("No %d\n",nl-a);
    return 0;
}
