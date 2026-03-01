#include <stdio.h>
int main(){
    int n[10]={0};
    for(int i=0;i<10;i++){
        scanf("%d",&n[i]);
    }
    for(int i=1;i<10;i++){
        if(n[i]){
            printf("%d",i);
            n[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<n[i];j++)
            printf("%d",i);
    }
    printf("\n");
    return 0;
}
