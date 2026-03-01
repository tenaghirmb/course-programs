#include <stdio.h>
int main(){
    int n,o=0,p=0,q=0,x=0,y=0,z=0,B1=0,C1=0,J1=0,B2=0,C2=0,J2=0;
    char a,b;
    scanf("%d\n",&n);
    while(n--){
	scanf("%c %c\n",&a,&b);
	if(a==b){
	    p++;
	    y++;
        }
	else if(a=='J'&&b=='B'){
	    o++;
	    z++;
	    J1++;
	}
	else if(a=='B'&&b=='J'){
	    q++;
	    x++;
	    J2++;
	}
	else if(a=='B'&&b=='C'){
	    o++;
	    z++;
	    B1++;
	}
	else if(a=='C'&&b=='B'){
	    q++;
	    x++;
	    B2++;
	}
	else if(a=='C'&&b=='J'){
	    o++;
	    z++;
	    C1++;
	}
	else if(a=='J'&&b=='C'){
	    q++;
	    x++;
	    C2++;
	}
    }
    printf("%d %d %d\n%d %d %d\n",o,p,q,x,y,z);
    a = B1>=C1?B1>=J1?'B':'J':C1>=J1?'C':'J';
    b = B2>=C2?B2>=J2?'B':'J':C2>=J2?'C':'J';
    printf("%c %c\n",a,b);
    return 0;
}
