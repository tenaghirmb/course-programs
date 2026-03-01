#include <stdio.h>
int main(){
    char cp[4][61],res[2],c;
    int i,j=0;
    for(i=0;i<4;i++)
	gets(cp[i]);
    i=0;
    while(j<1&&cp[0][i]&&cp[1][i]){
	if(cp[0][i]==cp[1][i]&&cp[0][i]-'A'>=0&&cp[0][i]-'A'<7)
	    {res[j++]=cp[0][i];  break;}
	i++;
    }
    i++;
    while(j<2&&cp[0][i]&&cp[1][i]){
	if(cp[0][i]==cp[1][i]&&(cp[0][i]-'A'>=0&&cp[0][i]<='N'||cp[0][i]-'0'<10&&cp[0][i]-'0'>=0))
	    {res[j++]=cp[0][i];  break;}
	i++;
    }
    for(i=0;i<60;i++){
	c=cp[2][i];
	if(c==cp[3][i]&&(c>='A'&&c<='Z'||c>='a'&&c<='z'))
	    break;
    }
    switch(res[0]){
	case 'A':  printf("MON ");  break;
	case 'B':  printf("TUE ");  break;
	case 'C':  printf("WED ");  break;
	case 'D':  printf("THU ");  break;
	case 'E':  printf("FRI ");  break;
	case 'F':  printf("SAT ");  break;
	case 'G':  printf("SUN ");  break;
    }
    if(res[1]-'0'<10)  printf("%02d:",res[1]-'0');
    else  printf("%02d:",res[1]-'A'+10);
    printf("%02d\n",i);
    return 0;
} 
