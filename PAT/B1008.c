#include <stdio.h>
int main(){
    int m,n,a[100],i=0,temp=0;
    scanf("%d%d",&n,&m);
    while(i<n){
	scanf("%d",&a[i]);
	i++;
    }
    while(m--){
	temp = a[n-1];
	for(i=0;i<n-1;i++)
	    a[n-1-i] = a[n-2-i];
	a[0] = temp;
    }
    for(i=0;i<n-1;i++)
	printf("%d ",a[i]);
    printf("%d\n",a[i]);
    return 0;
}
