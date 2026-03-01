#include <stdio.h>
int main(){
    int n;
    int x=0;
    scanf("%d",&n);
    while(n!=1){
        if(n%2==0)
            n/=2;
	else
	    n=(3*n+1)/2;
	x++;
    }
    printf("%d\n",x);
    return 0;
}

