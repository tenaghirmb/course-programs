#include <stdio.h>
int main(){
    int a,b,d,m,x[30]={0},i=0;
    scanf("%d%d%d",&a,&b,&d);
    m = a+b;
  if(m){
    while(m){
	x[i++]=m%d;
	m/=d;
    }
    for(i-=1;i>=0;i--)
	printf("%d",x[i]);
    printf("\n");
  }
  else printf("0\n");
    return 0;
}
