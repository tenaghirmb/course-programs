#include <stdio.h>
#include <string.h>
int main(){
    int la,lb,lc,ai,bi,i=1; 
    char a[101],b[101],c[101];
    scanf("%s",a);
    scanf("%s",b);
    la=strlen(a)-1;
    lb=strlen(b)-1;
    lc=la>lb?la:lb;
    while(i<lc+2){
	ai=la>=0?a[la]-'0':0;
	bi=lb>=0?b[lb]-'0':0;
	if(i%2==1){
	    switch((ai+bi)%13){
		case 10:  c[i-1]='J'; break;
		case 11:  c[i-1]='Q'; break;
		case 12:  c[i-1]='K'; break;
		default:  c[i-1]=(ai+bi)%13+'0';
	    }
	}
	else{
	    if(bi<ai)
		c[i-1]=(bi-ai)+10+'0';
	    else
		c[i-1]=bi-ai+'0';
	}
	i++;
	la--;
	lb--;
    }
    for(i=lc;i>=0;i--)
	printf("%c",c[i]);
    printf("\n");
    return 0;
}
