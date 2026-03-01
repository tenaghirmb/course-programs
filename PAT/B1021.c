#include <stdio.h>
int main(){
    int n[10]={0},i=0;
    char x[1000]={'0'};
    while(scanf("%c",&x[i++])!=EOF&&x[i-1]!='\n'){
	n[x[i-1]-'0']++;
    }
    for(i=0;i<10;i++)
	if(n[i])
	    printf("%d:%d\n",i,n[i]);
    return 0;
}
