#include <stdio.h>
int main(){
    int N,s[1000]={0},dw,dy,cj,max=0,temp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
	scanf("%d%d%d",&dw,&dy,&cj);
	s[dw]+=cj;
	if(s[dw]>max){
	    max=s[dw];
	    temp=dw;
	}
    }
    printf("%d %d\n",temp,max);
    return 0;
}
