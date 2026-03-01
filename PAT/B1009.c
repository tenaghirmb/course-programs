#include <stdio.h>
#include <string.h>
int main(){
    char d[81];
    int i=0,n=0;
    gets(d);
    n=strlen(d)-1;
    for(i=n;i>=0;i--){
	if(d[i]==' '){
	    for(int j=i+1;j<=n;j++)
		printf("%c",d[j]);
	    printf(" ");
	    n=i-1;
	}
	if(!i){
	   for(int j=0;j<=n;j++)
		printf("%c",d[j]);
	   printf("\n");
	}   
    }
    return 0;
}
