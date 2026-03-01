#include <stdio.h>
int main(){
    int i=0,sum=0,res[3]={0};
    char n[100]={'X'};
    scanf("%s",n);
    while((n[i]-'0')>=0&&(n[i]-'0'<=9)){
	sum+=n[i++]-'0';
    }
    i=0;
    while(sum){
	res[i++]=sum%10;
	sum/=10;
    }
    for(i-=1;i>=0;i--){
	switch(res[i]){
	    case 0: printf("ling"); break;
	    case 1: printf("yi");   break;
	    case 2: printf("er");   break;
	    case 3: printf("san");  break;
	    case 4: printf("si");   break;
	    case 5: printf("wu");   break;
	    case 6: printf("liu");  break;
	    case 7: printf("qi");   break;
	    case 8: printf("ba");   break;
	    case 9: printf("jiu");  break;
	}
	if(!i)  printf("\n");
	else    printf(" ");
    }
    return 0;
}
