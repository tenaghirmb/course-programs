#include <stdio.h>
int main(){
    int pg=0,ps=0,pk=0,ag=0,as=0,ak=0,rg=0,rs=0,rk=0,flag=0;
    long p=0,a=0,res=0;
    scanf("%d.%d.%d %d.%d.%d",&pg,&ps,&pk,&ag,&as,&ak);
    p = pg*17*29+ps*29+pk;
    a = ag*17*29+as*29+ak;
    res = a-p;
    if(res<0)  {res=-res;  flag=1;}
    rk = res%29;
    res/=29;
    rs = res%17;
    rg = res/17;
    if(flag)  printf("-");
    printf("%d.%d.%d\n",rg,rs,rk);
    return 0;
}
