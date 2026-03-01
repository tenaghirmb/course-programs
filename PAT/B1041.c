#include <stdio.h>
int main(){
    int n,m,x[1000]={0},i,b,c;
    long t[1000]={0},a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%ld%d%d",&a,&b,&c);
	t[b]=a;
	x[b]=c;
    }
    scanf("%d",&m);
    while(m--){
	scanf("%d",&i);
	printf("%ld %d\n",t[i],x[i]);
    }
    return 0;
}
