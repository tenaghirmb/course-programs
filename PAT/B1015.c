#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int N,L,H,M=0;
struct Student{
    char sno[9];
    int  ms;
    int  ss;
    int  ts;
    int  level;
}stu[100000];
bool cmp(Student a,Student b){
    if(a.level!=b.level)  return a.level>b.level;
    else if(a.ts!=b.ts)  return a.ts>b.ts;
    else if(a.ms!=b.ms)  return a.ms>b.ms;
    else return strcmp(b.sno,a.sno)>0;
}
int classify(Student s){
    if(s.ms<L||s.ss<L)
	s.level=0;
    else if(s.ms>=H&&s.ss>=H)
	s.level=4;
    else if(s.ss<H&&s.ms>=H)
	s.level=3;
    else if(s.ms<H&&s.ss<H&&s.ms>=s.ss)
	s.level=2;
    else s.level=1;
    return s.level;
}
int main(){
    int l;
    Student x;
    scanf("%d%d%d",&N,&L,&H);
    for(int i=0;i<N;i++){
	scanf("%s%d%d",x.sno,&x.ms,&x.ss);
        l=classify(x);
	if(l){
	    strcpy(stu[M].sno,x.sno);
	    stu[M].ms=x.ms;
	    stu[M].ss=x.ss;
	    stu[M].ts=x.ms+x.ss;
	    stu[M].level=l;
	    M++;
	}
    }
    printf("%d\n",M);
    if(M){
	sort(stu,stu+M,cmp);
	for(int i=0;i<M;i++)
 	    printf("%s %d %d\n",stu[i].sno,stu[i].ms,stu[i].ss);
    }
    return 0;
}
