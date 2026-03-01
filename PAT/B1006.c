#include <stdio.h>
int main(){
    int b=0,s=0,g=0,n;
    scanf("%d",&n);
    if(!n)  printf("0\n");
    else{
	g=n%10;
	n/=10;
	s=n%10;
	b=n/10;
	if(b)
	    for(int i=0;i<b;i++)
		printf("B");
	if(s)
	    for(int i=0;i<s;i++)
		printf("S");
	for(int i=1;i<g+1;i++)
	    printf("%d",i);
	printf("\n");
    }
    return 0;
}
