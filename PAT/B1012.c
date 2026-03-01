#include <stdio.h>
int main(){
    int n,i=0,t[1000]={0},a=0,b=0,c=0,e=0,p=0,q=0,temp;
    double d=0,sum=0;
    scanf("%d",&n);
    while(n--){
	scanf("%d",&temp);
	switch(temp%5){
	    case 1:
	        t[p++]=temp;
	        break;
	    case 2:
	        c++;
	        break;
	    case 3:
		t[999-q++]=temp;
	        break;
	    case 4:
	        e = temp>e?temp:e;
	        break;
	    default:
	        if(temp%2==0)  a+=temp;
	}
    }
    while(i<p){
	b+=t[i];
	i+=2;
    }
    i=1;
    while(i<p){
	b-=t[i];
	i+=2;
    }
    for(i=0;i<q;i++)
	sum+=t[999-i];
    if(q)  d = sum/q;
    if(a)
	printf("%d ",a);
    else
	printf("N ");
    if(p)
	printf("%d ",b);
    else
        printf("N ");
    if(c)
	printf("%d ",c);
    else
        printf("N ");
    if(d)
	printf("%.1f ",d);
    else
        printf("N ");
    if(e)
	printf("%d\n",e);
    else
        printf("N\n");
    return 0;
}
