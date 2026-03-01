#include <stdio.h>
int main(){
    int T,i=0;
    long a,b,c;
    scanf("%d",&T);
    while(T--){
        scanf("%ld %ld %ld",&a,&b,&c);
	i++;
	if(a+b>c)
	    printf("Case #%d: true\n",i);
	else
	    printf("Case #%d: false\n",i);
    }
    return 0;
}
