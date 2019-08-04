#include <bits/stdc++.h> 
using namespace std; 

int n=6;
void knight(int i,int j,int a[10][10],int moves) 
{ 
	if(i>=n or i<0 or j>=n or j<0 or moves>n*n or a[i][j]!=0)
		return;
	//printf("%d\n",moves);
	a[i][j]=moves;
	if(moves==n*n)
	{
		for(int i=0;i<n;i++)
	   {
	   	for(int j=0;j<n;j++)
	   	{
	   		printf("%d ",a[i][j]);
	   	}
	   	printf("\n");
	   }
	   exit(0);
	}
	knight(i+2,j+1,a,moves+1);
	knight(i+2,j-1,a,moves+1);
	knight(i-2,j+1,a,moves+1);
	knight(i-2,j-1,a,moves+1);
	knight(i+1,j+2,a,moves+1);
	knight(i+1,j-2,a,moves+1);
	knight(i-1,j+2,a,moves+1);
	knight(i-1,j-2,a,moves+1);
	a[i][j]=0;
} 

int main() 
{ 
	int a[10][10]={0};
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	{
   		if(a[i][j]==0)
   			knight(i,j,a,1);
   	}
   }
   return 0; 
} 