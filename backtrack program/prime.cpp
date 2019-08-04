#include <bits/stdc++.h> 
using namespace std; 
bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

void prime(int n,int p,int s,int depth,int a[20]) 
{ 
	if(s<0 or depth>=n)
		return;
	//printf("%d %d %d\n",p,depth,s);
	a[depth]=p;
	if(depth==n-1 and s==0)
	{
		for(int i=0;i<n;++i)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	for(int i=p+1;i<=s;i++)
		if(isprime(i))
			prime(n,i,s-i,depth+1,a);
	a[depth]=0;	
} 

int main() 
{ 
	int n,p,s;
	int a[20]={0};
	cin>>n>>p>>s;
	for(int i=p+1;i<=s;i++)
	{
		//printf("%d ",i);
		if(isprime(i))
			prime(n,i,s-i,0,a);
	}	
   return 0; 
} 