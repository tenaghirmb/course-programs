#include <stdio.h>
#include <string.h>
int main(){
    int n,m=0,yy,mm,dd,age,ageo=-1,agey=72001;
    char name[6],no[6],ny[6];
    scanf("%d",&n);
    while(n--){
	scanf("%s%d/%d/%d",name,&yy,&mm,&dd);
	age = (2014-yy)*360+(9-mm)*30+(6-dd);
	if(age>=0&&age<=72000){
	    m++;
	    if(age<agey)  {agey=age;  strcpy(ny,name);}
	    if(age>ageo)  {ageo=age;  strcpy(no,name);}
	}
    }
    if(m)
        printf("%d %s %s\n",m,no,ny);
    else
	printf("0\n");
    return 0;
}
