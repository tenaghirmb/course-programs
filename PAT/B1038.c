#include <stdio.h>
int main(){
    int N,K,s[100]={0},x;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
	scanf("%d",&x);
	s[x]++;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
	scanf("%d",&x);
	printf("%d",s[x]);
	if(i==K-1)  printf("\n");
	else  printf(" ");
    }
    return 0;
}
