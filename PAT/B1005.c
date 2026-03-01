#include <stdio.h>
void Callatz(int x,int *p){
    while(x!=1){
	if(x%2){
	    x=(3*x+1)/2;
	    if(x<101)  *(p+x)=0;
	}
	else{
	    x=x/2;
	    if(x<101)  *(p+x)=0;
	}
    }
}
int main(){
    int K,n[100]={0},t[100],max=0,temp=0,r[100];
    scanf("%d",&K);
    for(int i=0;i<K;i++){
	scanf("%d",&t[i]);
	if(t[i]>max)  max=t[i];
	n[t[i]]=1;
    }
    for(int i=0;i<K;i++){
	Callatz(t[i],n);
    }
    for(int i=max;i>1;i--){
	if(n[i])
	    r[temp++]=i;
    }
    for(int i=0;i<temp;i++){
	printf("%d",r[i]);
	if(i==temp-1)  printf("\n");
	else printf(" ");
    }
    return 0;
}
