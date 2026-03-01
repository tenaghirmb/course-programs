#include <stdio.h>
#include <math.h>
int main(){
    int n,m=0,r=0;
    char c;
    scanf("%d %c\n",&n,&c);
    m = (int)sqrt((n+1)/2)-1;
    r = n-2*m*(m+2)-1;
    m = 2*m+1;
    for(int j=m;j>0;j-=2){
        for(int i=0;i<(m-j)/2;i++)
            printf(" ");
        for(int i=0;i<j;i++)
            printf("%c",c);
        printf("\n");
    }
    for(int j=3;j<m+1;j+=2){
        for(int i=0;i<(m-j)/2;i++)
            printf(" ");
        for(int i=0;i<j;i++)
            printf("%c",c);
        printf("\n");
    }
    if(r)  printf("%d\n",r);
    return 0;
}
