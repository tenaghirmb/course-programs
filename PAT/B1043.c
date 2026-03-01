#include <stdio.h>
#include <string.h>
int main(){
    char n[10001];
    int w[6]={0},nl;
    gets(n);
    nl=strlen(n);
    for(int i=0;i<nl;i++){
	switch(n[i]){
	    case 'P':  w[0]++;  break;
	    case 'A':  w[1]++;  break;
	    case 'T':  w[2]++;  break;
	    case 'e':  w[3]++;  break;
	    case 's':  w[4]++;  break;
	    case 't':  w[5]++;  break;
	}
    }
    while(w[0]||w[1]||w[2]||w[3]||w[4]||w[5]){
	for(int i=0;i<6;i++){
	    if(w[i]){
		switch(i){
		    case 0:  printf("P"); break;
		    case 1:  printf("A"); break;
		    case 2:  printf("T"); break;
		    case 3:  printf("e"); break;  
		    case 4:  printf("s"); break;
		    case 5:  printf("t"); break;
		}
		w[i]--;
	    }
	}
    }
    printf("\n");
    return 0;
}
