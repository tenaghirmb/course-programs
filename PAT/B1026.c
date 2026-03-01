#include <stdio.h>
#include <math.h>
int main(){
    int a,b,h,m,s;
    double time;
    scanf("%d%d",&a,&b);
    time = (b-a)/100.0;
    h = time/3600;
    time-=h*3600;
    m = time/60;
    time-=m*60;
    s = round(time);
    printf("%02d:%02d:%02d\n",h,m,s);     
    return 0;
}
