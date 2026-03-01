#include <stdio.h>
int main(){
    int a=0,n=0,i=0,x[4000]={0};
    while(scanf("%d%d",&a,&n)!=EOF){
	if(a*n){
	    x[i++]=a*n;
	    x[i++]=n-1;
	}    
    }
    i=0;
    if(!x[i]) printf("0 0\n");
    else{
        while(x[i]){
	    printf("%d %d",x[i],x[i+1]);
	    if(x[i+2])  printf(" ");
      	    else  printf("\n");
	    i+=2;
        }
    }
    return 0;
}
