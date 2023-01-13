#include<stdio.h>
int main(){
	int n;
	long long ans=0;
	int i;
	scanf("%d",&n);
	if(n%2==0)for(i=1;i<n;i+=2)ans+=i;
	else for(i=0;i<n;i+=2)ans+=i;
	printf("%lld",ans*2);
	return 0;
}