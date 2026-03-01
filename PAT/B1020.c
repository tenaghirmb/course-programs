#include <stdio.h>
#include <algorithm>
using namespace std;
struct mooncake{
    double kc;
    double sj;
    double dj;
}t[1000];
bool cmp(mooncake m,mooncake n){
    return m.dj>n.dj;
}
int main(){
    int N,D;
    double p=0;
    scanf("%d%d",&N,&D);
    for(int i=0;i<N;i++)
        scanf("%lf",&t[i].kc);
    for(int i=0;i<N;i++){
        scanf("%lf",&t[i].sj);
        t[i].dj=t[i].sj/t[i].kc;
    }
    sort(t,t+N,cmp);
    for(int i=0;i<N;i++){
        if(t[i].kc>=D){
            p+=t[i].dj*D;
            D=0;
        }
        else{
            p+=t[i].sj;
            D-=t[i].kc;
        }
    }
    printf("%.2f\n",p);
    return 0;
}

