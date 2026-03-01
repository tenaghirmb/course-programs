#include <stdio.h>
int main(){
    int n,x[100000]={0},i,s,ts=0,sno=0;
    scanf("%d",&n);
    while(n--){
	scanf("%d%d",&i,&s);
	x[i]+=s;
	if(x[i]>ts)  {sno=i;  ts=x[i];}
    }
    printf("%d %d\n",sno,ts);
    return 0;
}
