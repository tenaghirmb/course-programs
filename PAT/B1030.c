# include <stdio.h>
# include <algorithm>
using namespace std;
long int seq[100001];
int N;
int BinarySearch(int i,long long int x){
	if(seq[N-1]<=x)
		return N;
	int mid,l=i+1,r=N-1;
	while(l<r){
		mid = (r+l)/2;
		if(seq[mid]<=x){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	return l;
}
int main(){
	int res=0,temp;
	long int p;
	scanf("%d%ld",&N,&p);
	for(int i=0;i<N;i++){
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+N);
	for(int i=0;i<N;i++){
		temp = BinarySearch(i,(long long int)seq[i]*p)-i;
		res = max(temp,res);
	}
	printf("%d\n",res);
	return 0;
}
