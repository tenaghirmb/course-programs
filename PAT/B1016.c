#include <stdio.h>
#include <math.h>
int main(){
    long a,b,m=0,n=0;
    int p,q,i=0;
    scanf("%ld%d%ld%d",&a,&p,&b,&q);
    while(a){
	if(a%10==p)
	    m+=p*pow(10,i++);
	a/=10;
    }
    i=0;
    while(b){
	if(b%10==q)
	    n+=q*pow(10,i++);
	b/=10;
    }
    printf("%ld\n",m+n);
    return 0;
}
