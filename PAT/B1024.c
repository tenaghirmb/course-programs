#include <stdio.h>
int main(){
    int i=0,e,exp=0;
    char n[10000]={'X'};
    gets(n);
    if(n[0]=='-')  printf("-");
    while(n[i]!='E')  i++;
    e=i;
    i+=2;
    while(n[i]<='9'&&n[i]>='0'){
	exp=exp*10+n[i]-'0';
	i++;
    }
    if(n[e+1]=='-'){
	printf("0.");
	for(i=0;i<exp-1;i++)
	    printf("0");
	printf("%c",n[1]);
	for(i=3;i<e;i++)
	    printf("%c",n[i]);
    }
    else{
	printf("%c",n[1]);
	if(e-3<=exp){
	    for(i=3;i<e;i++)
		printf("%c",n[i]);
	    for(i=0;i<exp-e+3;i++)
		printf("0");
	}
	else{
	    for(i=3;i<exp+3;i++)
		printf("%c",n[i]);
	    printf(".");
	    for(;i<e;i++)
		printf("%c",n[i]);
	}
    }
    printf("\n");
    return 0;
}
