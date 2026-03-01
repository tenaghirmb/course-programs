#include <stdio.h>
#include <math.h>
int main(){
    int n,m=0;
    char c;
    scanf("%d %c\n",&n,&c);
    m = round(n/2.0);
    for(int i=0;i<n;i++)
	printf("%c",c);
    printf("\n");
    for(int i=0;i<m-2;i++){
	printf("%c",c);
	for(int j=0;j<n-2;j++)
	    printf(" ");
	printf("%c\n",c);
    }
    for(int i=0;i<n;i++)
	printf("%c",c);
    printf("\n");
    return 0;
}
