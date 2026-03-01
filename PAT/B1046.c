#include <stdio.h>
int main(){
    int a,b,c,d,m=0,n=0,i;
    scanf("%d",&i);
    while(i--){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if((b==a+c)&&(d!=a+c))  n++;
	else if((b!=a+c)&&(d==a+c))  m++;
    }
    printf("%d %d\n",m,n);
    return 0;
}
