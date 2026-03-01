#include <stdio.h>
#include <string.h>
int main(){
    int n,i,grade,high=-1,low=101;
    char name[11],sno[11],xh[11],yh[11],xl[11],yl[11];
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%s%s%d",name,sno,&grade);
	if(grade>high)  {high=grade;  strcpy(xh,name);  strcpy(yh,sno);}
        if(grade<low)  {low=grade;  strcpy(xl,name);  strcpy(yl,sno);}
    }
    printf("%s %s\n",xh,yh);
    printf("%s %s\n",xl,yl);
    return 0;
}
