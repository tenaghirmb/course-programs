#include <stdio.h>
int main(){
    int N,i,sum,flag,err=0,z;
    char x[19],c;
    scanf("%d",&N);
    while(N--){
	sum=0;
	flag=0;
	scanf("%s",x);
	for(i=0;i<18;i++){
	    if(x[i]=='X'&&i!=17)
		flag=1;
	    if(!flag){
	        switch(i){
		    case 0:
		    case 10:
		        sum+=(x[i]-'0')*7;
		        break;
		    case 1:
		    case 11:
		        sum+=(x[i]-'0')*9;
		        break;
		    case 2:
		    case 12:
		        sum+=(x[i]-'0')*10;
		        break;
		    case 3:
		    case 13:
		        sum+=(x[i]-'0')*5;
		        break;
		    case 4:
		    case 14:
		        sum+=(x[i]-'0')*8;
		        break;
		    case 5:
	 	    case 15:
		        sum+=(x[i]-'0')*4;
		        break;
		    case 6:
		    case 16:
		        sum+=(x[i]-'0')*2;
		        break;
		    case 7:
		        sum+=x[i]-'0';
		        break;
		    case 8:
		        sum+=(x[i]-'0')*6;
		        break;
		    case 9:
		        sum+=(x[i]-'0')*3;
		        break;
	        }
	    }
	}
        if(!flag){
	    z=sum%11;
	    switch(z){
                case 0:
	        case 1:
	            c=(1-z)+'0';
	            break;
	        case 2:
	            c='X';
	            break;
	        default:
	            c=(12-z)+'0';
	    }
	    if(c!=x[17])  flag=1;
	}
	if(flag)  {err=1;  printf("%s\n",x);}
    } 
    if(!err)  printf("All passed\n");
    return 0;
}
